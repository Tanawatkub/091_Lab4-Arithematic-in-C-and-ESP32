#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// กำหนดชื่อสำหรับแสดงใน log
static const char *TAG = "BOOKS_COUNT";

void app_main(void)
{
    ESP_LOGI(TAG, "📚 เริ่มต้นโปรแกรมนับหนังสือบนชั้น 📚");
    ESP_LOGI(TAG, "=====================================");
    
    // ประกาศตัวแปรเก็บจำนวนหนังสือ
    int books_already_on_shelf = 8;    // มีอยู่เดิม 8 เล่ม
    int books_added_today = 3;         // วันนี้เอามาเพิ่มอีก 3 เล่ม
    int total_books;                   // หนังสือรวมทั้งหมด
    int magazines = 3;                 // นิตยสารที่มีในชั้นเดียวกัน
    int total_all_items;               // รวมหนังสือ + นิตยสาร
    
    // แสดงข้อมูลเริ่มต้น
    ESP_LOGI(TAG, "📖 โจทย์:");
    ESP_LOGI(TAG, "   เดิมบนชั้นมีหนังสือ: %d เล่ม", books_already_on_shelf);
    ESP_LOGI(TAG, "   วันนี้เอามาเพิ่มอีก: %d เล่ม", books_added_today);
    ESP_LOGI(TAG, "   ❓ ตอนนี้บนชั้นมีหนังสือทั้งหมดกี่เล่ม?");
    ESP_LOGI(TAG, "");
    
    // รอสักครู่เพื่อให้อ่านโจทย์
    vTaskDelay(3000 / portTICK_PERIOD_MS);
    
    // คำนวณผลรวม
    total_books = books_already_on_shelf + books_added_today;
    total_all_items = total_books + magazines;

    // แสดงข้อมูลนิตยสาร
    ESP_LOGI(TAG, "🗞️ และยังมีนิตยสารอีก: %d เล่ม", magazines);
    ESP_LOGI(TAG, "📚 รายการทั้งหมด (หนังสือ+นิตยสาร): %d รายการ", total_all_items);
    
    // แสดงขั้นตอนการคิด
    ESP_LOGI(TAG, "🧮 ขั้นตอนการคิด:");
    ESP_LOGI(TAG, "   หนังสือเดิม + หนังสือที่เอาเพิ่ม");
    ESP_LOGI(TAG, "   = %d + %d", books_already_on_shelf, books_added_today);
    ESP_LOGI(TAG, "   = %d เล่ม", total_books);
    ESP_LOGI(TAG, "");
    
    // แสดงคำตอบ
    ESP_LOGI(TAG, "✅ คำตอบ:");
    ESP_LOGI(TAG, "   ตอนนี้มีหนังสือทั้งหมด %d เล่ม", total_books);
    ESP_LOGI(TAG, "");
    
    // แสดงภาพประกอบ (ASCII Art)
    ESP_LOGI(TAG, "🎨 ภาพประกอบ:");
    ESP_LOGI(TAG, "   หนังสือเดิม: 📘📘📘📘 (%d เล่ม)", books_already_on_shelf);
    ESP_LOGI(TAG, "   หนังสือใหม่: 📕📕 (%d เล่ม)", books_added_today);
    ESP_LOGI(TAG, "   รวม:        📗📗📗📗📗📗 (%d เล่ม)", total_books);
    ESP_LOGI(TAG, "");
    
    // ตัวอย่างเพิ่มเติม
    ESP_LOGI(TAG, "💡 ตัวอย่างเพิ่มเติม:");
    
    // ตัวอย่างที่ 1
    int example1_old = 7;
    int example1_new = 3;
    int example1_total = example1_old + example1_new;
    ESP_LOGI(TAG, "   ถ้ามีหนังสืออยู่แล้ว %d เล่ม และเพิ่มอีก %d เล่ม", example1_old, example1_new);
    ESP_LOGI(TAG, "   จะได้หนังสือทั้งหมด %d + %d = %d เล่ม", example1_old, example1_new, example1_total);
    ESP_LOGI(TAG, "");
    
    // ตัวอย่างที่ 2
    int example2_old = 10;
    int example2_new = 5;
    int example2_total = example2_old + example2_new;
    ESP_LOGI(TAG, "   ถ้ามีหนังสืออยู่แล้ว %d เล่ม และเพิ่มอีก %d เล่ม", example2_old, example2_new);
    ESP_LOGI(TAG, "   จะได้หนังสือทั้งหมด %d + %d = %d เล่ม", example2_old, example2_new, example2_total);
    ESP_LOGI(TAG, "");
    
    // สรุปการเรียนรู้
    ESP_LOGI(TAG, "📚 สิ่งที่เรียนรู้:");
    ESP_LOGI(TAG, "   1. การบวกเลข (Addition): a + b = c");
    ESP_LOGI(TAG, "   2. การใช้ตัวแปร (Variables) เก็บค่า");
    ESP_LOGI(TAG, "   3. การแสดงผลด้วย ESP_LOGI");
    ESP_LOGI(TAG, "   4. การแก้โจทย์แบบมีขั้นตอน");
    ESP_LOGI(TAG, "");
    
    ESP_LOGI(TAG, "🎉 จบโปรแกรมนับหนังสือบนชั้น!");
    ESP_LOGI(TAG, "📖 อ่านต่อในโปรเจคถัดไป: 02_subtraction_toys");
    
    // รอสักครู่ก่อนจบโปรแกรม
    vTaskDelay(2000 / portTICK_PERIOD_MS);
}
