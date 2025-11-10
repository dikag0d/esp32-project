# esp32-project
# Andika Nugraha-3223600010
Matakuliah Sistem Embedded 
Konsep Multitasking dan Dual-Core Processing Mikrokontroler ESP32-S3
Andika Nugraha - 3223600010 - 3 D4 Teknik Komputer A

Pin yang di gunakan
____________________________________________________
| Komponen           | Pin ESP32-S3 | Keterangan   |
| ------------------ | ------------ | ------------ |
| LED                | 15           | Output       |
| Buzzer             | 4            | Output       |
| Push Button 1      | 18           | Input        |
| Push Button 2      | 19           | Input        |
| Potensiometer      | 36           | Analog input |
| OLED SDA           | 8            | I2C data     |
| OLED SCL           | 9            | I2C clock    |
| Rotary Encoder CLK | 10           | Input A      |
| Rotary Encoder DT  | 11           | Input B      |
| Rotary Encoder SW  | 12           | Push switch  |
| Servo PWM          | 42           | Output PWM   |
| Stepper B-         | 37           | Output coil  |
| Stepper B+         | 38           | Output coil  |
| Stepper A+         | 39           | Output coil  |
| Stepper A-         | 40           | Output coil  |
____________________________________________________

Atau bisa lihat diagram.json WokWi

Tujuan Percobaan
-Menguji fungsi masing-masing peripheral pada ESP32-S3
-Mengamati perbedaan performa task yang dijalankan di Core 0 dan Core 1.
-Mengetahui kestabilan akses I/O, PWM, ADC, dan I²C pada lingkungan multitasking.

# Langkah Percobaan per Peripheral
1.LED Test
Tujuan: Menguji output digital.
Jalankan led_test.ino
LED di GPIO15 berkedip setiap 500 ms.
Jalankan di Core 0, lalu ubah ke Core 1.
Bandingkan kestabilan waktu kedip.

2️.Buzzer Test

Tujuan: Menguji output digital (bunyi).
Jalankan buzzer_test.ino
Buzzer aktif selama 300 ms tiap 1 detik.
Bandingkan nada atau timing antar core.

3️.Push Button Test
Tujuan: Menguji input digital dengan pull-up.
Jalankan button.ino
Tekan tombol 1 (GPIO18) atau 2 (GPIO19).
LED GPIO15 menyala saat tombol ditekan.
Ubah core eksekusi task dan amati respon.

4️.Potensiometer Test
Tujuan: Membaca nilai analog.
Jalankan potentio.ino
Putar knob potensiometer.
Nilai ADC tampil di Serial Monitor (0–4095).
Bandingkan hasil pembacaan di Core 0 dan 1.

5️.OLED Display Test
Tujuan: Menampilkan teks pada OLED SSD1306.
Jalankan oled.ino
Teks OLED Task running on Core: tampil di layar.
Ubah core dan amati apakah tampilan tetap stabil.

6️.Rotary Encoder Test
Tujuan: Membaca arah dan langkah putaran.
Jalankan encoder.ino
Putar knob searah atau berlawanan jarum jam.
Nilai counter bertambah/berkurang di Serial Monitor.
Bandingkan kecepatan respon antar core.

7️.Servo Test
Tujuan: Menguji kontrol PWM.
Jalankan servo.ino
Servo bergerak 0° → 180° → 0° berulang.
Jalankan di Core 0 lalu di Core 1.
Catat kestabilan sudut dan getaran.

8️.Stepper Motor Test
Tujuan: Menguji urutan coil stepper.
Jalankan stepper.ino
Motor berputar CW lalu CCW.
Bandingkan kelancaran di Core 0 dan Core 1.


# Penjelasan Fungsi xTaskCreatePinnedToCore()
Fungsi ini adalah bagian penting dari FreeRTOS yang digunakan untuk membuat task baru dan menentukan core mana yang akan menjalankannya.
xTaskCreatePinnedToCore(function_name,task_name,stack_size,task_parameter,priority,task_handle,core_ID);


Contoh : xTaskCreatePinnedToCore(taskLED, "taskLED_Core0", 1000, NULL, 1, NULL, 0);


# Perbedaan Core 0 dan Core 1
| Core       | Fungsi Utama                            | Keterangan                                                  |
| ---------- | --------------------------------------- | ----------------------------------------------------------- |
| **Core 0** | Sistem, Wi-Fi, Bluetooth, task tambahan | Dapat digunakan untuk tugas rutin atau proses berat         |
| **Core 1** | Program utama (Arduino loop, setup)     | Biasanya digunakan untuk task utama seperti UI, sensor      |

# Kesimpulan

Dengan FreeRTOS, ESP32-S3 dapat menjalankan beberapa proses (task) secara bersamaan di dua core.
Fungsi xTaskCreatePinnedToCore() memungkinkan pembagian kerja antar-core secara manual.
Pembagian tugas yang baik (misalnya LED di Core 0 dan sensor di Core 1) dapat meningkatkan performa sistem dan membuat respon lebih cepat.
