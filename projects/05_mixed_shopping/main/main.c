#include <stdio.h>
#include <string.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "SHOPPING_MATH";

typedef struct {
    char name[20];
    int quantity;
    float price_per_unit;
    float total_price;
} product_t;

void calculate_product_total(product_t *product) {
    product->total_price = product->quantity * product->price_per_unit;
}

void display_product(const product_t *product) {
    ESP_LOGI(TAG, "   %s: %d × %.0f = %.0f บาท", 
             product->name, product->quantity, product->price_per_unit, product->total_price);
}

float calculate_total_bill(product_t products[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        calculate_product_total(&products[i]);
        total += products[i].total_price;
    }
    return total;
}

float apply_discount(float total, float discount_rate) {
    return total * (1.0 - discount_rate);
}

float apply_vat(float total, float vat_rate) {
    return total * (1.0 + vat_rate);
}

float split_payment(float amount, int people) {
    if (people <= 0) {
        ESP_LOGE(TAG, "Error: จำนวนคนต้องมากกว่า 0");
        return 0.0;
    }
    return amount / people;
}

void app_main(void)
{
    ESP_LOGI(TAG, "🛒 เริ่มต้นโปรแกรมซื้อของที่ตลาด 🛒");
    ESP_LOGI(TAG, "=====================================");

    product_t products[] = {
        {"แอปเปิ้ล", 6, 15.0, 0.0},
        {"กล้วย", 12, 8.0, 0.0},
        {"ส้ม", 8, 12.0, 0.0},
        {"มะม่วง", 5, 25.0, 0.0},
        {"เงาะ", 10, 10.0, 0.0},
        {"ทุเรียน", 2, 150.0, 0.0}
    };
    int product_count = sizeof(products) / sizeof(products[0]);

    float discount_rate = 0.10;   // ส่วนลด 10%
    float vat_rate = 0.07;        // VAT 7%
    int people = 3;

    ESP_LOGI(TAG, "📖 โจทย์:");
    for (int i = 0; i < product_count; i++) {
        ESP_LOGI(TAG, "   - %s: %d หน่วย หน่วยละ %.0f บาท", 
                 products[i].name, products[i].quantity, products[i].price_per_unit);
    }
    ESP_LOGI(TAG, "   - ส่วนลด: %.0f%%", discount_rate * 100);
    ESP_LOGI(TAG, "   - VAT: %.0f%%", vat_rate * 100);
    ESP_LOGI(TAG, "   - แบ่งจ่าย: %d คน", people);
    ESP_LOGI(TAG, "");

    vTaskDelay(3000 / portTICK_PERIOD_MS);

    float subtotal = calculate_total_bill(products, product_count);

    ESP_LOGI(TAG, "🧮 ขั้นตอนการคิด:");
    ESP_LOGI(TAG, "   1. คำนวณราคาแต่ละสินค้า:");
    for (int i = 0; i < product_count; i++) {
        display_product(&products[i]);
    }
    ESP_LOGI(TAG, "");

    ESP_LOGI(TAG, "   2. รวมราคาทั้งหมด:");
    ESP_LOGI(TAG, "      ยอดรวมก่อนส่วนลด: %.0f บาท", subtotal);

    float discounted_total = apply_discount(subtotal, discount_rate);
    ESP_LOGI(TAG, "   3. หักส่วนลด:");
    ESP_LOGI(TAG, "      %.0f - %.0f%% = %.2f บาท", subtotal, discount_rate * 100, discounted_total);

    float total_with_vat = apply_vat(discounted_total, vat_rate);
    ESP_LOGI(TAG, "   4. เพิ่ม VAT:");
    ESP_LOGI(TAG, "      %.2f + %.0f%% = %.2f บาท", discounted_total, vat_rate * 100, total_with_vat);

    float per_person = split_payment(total_with_vat, people);
    ESP_LOGI(TAG, "   5. แบ่งจ่าย:");
    ESP_LOGI(TAG, "      %.2f ÷ %d = %.2f บาท/คน", total_with_vat, people, per_person);
    ESP_LOGI(TAG, "");

    ESP_LOGI(TAG, "🧾 ใบเสร็จรับเงิน:");
    ESP_LOGI(TAG, "   ==========================================");
    ESP_LOGI(TAG, "   🏪 ตลาดสดใหม่ 🏪");
    ESP_LOGI(TAG, "   ==========================================");
    for (int i = 0; i < product_count; i++) {
        display_product(&products[i]);
    }
    ESP_LOGI(TAG, "   ----------------------------------------");
    ESP_LOGI(TAG, "   ยอดรวม:                    %.0f บาท", subtotal);
    ESP_LOGI(TAG, "   ส่วนลด:                   -%.0f%%", discount_rate * 100);
    ESP_LOGI(TAG, "   รวมหลังส่วนลด:            %.2f บาท", discounted_total);
    ESP_LOGI(TAG, "   VAT 7%%:                   +%.2f บาท", total_with_vat - discounted_total);
    ESP_LOGI(TAG, "   ========================================");
    ESP_LOGI(TAG, "   ยอดสุทธิ:                 %.2f บาท", total_with_vat);
    ESP_LOGI(TAG, "   แบ่งจ่าย %d คน:            %.2f บาท/คน", people, per_person);
    ESP_LOGI(TAG, "   ========================================");
    ESP_LOGI(TAG, "   ขอบคุณที่ใช้บริการ 😊");
    ESP_LOGI(TAG, "");

    vTaskDelay(2000 / portTICK_PERIOD_MS);
}
