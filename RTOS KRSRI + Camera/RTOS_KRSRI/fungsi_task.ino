void kaki(void *pvParameters) {
  while (1) {
    if (queue) {
      int receiveQueue = 0;
      if (xQueueReceive(queueHandle, &receiveQueue, 10) == pdTRUE) { //awal 10
        choice = receiveQueue;
        //        DEBUG_SERIAL.print("setelah kirim queue: ");
        //        DEBUG_SERIAL.println(choice);
        data = true;
      } else {
        queue = false;
        data = false;
      }
    }
    else {
      xSemaphoreTake(semHandle, 2500);
      choice = choice_sem;
      //      DEBUG_SERIAL.print("setelah kirim semaphore : ");
      //      DEBUG_SERIAL.println(choice);
      data = true;
    }

    if (data) {
      switch (choice) {
        case 1: jalanturunan(sudutBelok); break;
        case 2: kiripecah(sudutBelok); break;
        case 3: kiricepat(sudutBelok); break;
        case 4: jalanpecah1(sudutBelok); break;
        case 5: majudikitK1New(0); break;
        case 6: mundurdikitK1New(0); break;
        case 7: kanandikitK1FX(sudutBelok); break;
        case 8: kiridikitK1FX(sudutBelok); break;
        case 9: standby2(); break;
        case 10: grabK1(); break;
        case 11: turuncapit(); break;
        case 12: rotRight(abs(compassOffset)); break;
        case 13: rotLeft(abs(compassOffset)); break;
        case 14: rotRightStart(abs(SudutRotate)); break;
        case 15: rotLeftStart(abs(SudutRotate)); break;
        case 16: kananstartNew(sudutBelok); break;
        case 18: rotRightStart(abs(compassOffset)); break;
        case 19: rotLeftStart(abs(compassOffset)); break;
        case 20: TransisiTurunan(); break;
        case 21: majubatu(longStep); break;
        case 22: jalanbatu1(sudutBelok); break; //turunan
        case 23: grabK2(); break;
        case 25: taruhkorban(); break;
        case 26: kananbatu(sudutBelok); break;
        case 27: kiribatu(sudutBelok); break;
        case 29: majudikitK2(); break;
        case 30: mundurdikitK2(); break;
        case 31: kanandikitK2(); break;
        case 32: kiridikitK2(); break;
        case 34: mundurpecahV2(sudutBelok); break;
        case 35: break;
        case 36: rotRightKelereng(abs(compassOffset)); break;
        case 37: rotLeftKelereng(abs(compassOffset)); break;
        case 38: turuncapitK4(); break;
        case 39: rotRightPecah(abs(compassOffset)); break;
        case 40: rotLeftPecah(abs(compassOffset)); break;
        case 42: rotRightK1(abs(compassOffset)); break;
        case 43: rotLeftK1(abs(compassOffset)); break;
        case 44: Transisi1(); break;
        case 45: Transisi2(); break;
        //        case 46: taruhK1Inverse(); break;
        case 47: rotRightPecah(abs(compassOffset)); break;
        case 48: rotLeftPecah(abs(compassOffset)); break;
        case 49: standbyTransisi1(); break;
        case 50: standbyTransisi2(); break;
        case 51: rotRightTransisi(abs(compassOffset)); break;
        case 52: rotLeftTransisi(abs(compassOffset)); break;
        //        case 53: majustabil(sudutBelok); break;
        case 54: majudkt(); break;
        case 55: kiricpt(0); break;
        case 56: kanancpt(0); break;
        case 57: standby3(); break;
        case 58: naiktanggaFix3(); break;
        case 59: kiridikitK3(sudutBelok); break;
        case 60: kiricepatK3(sudutBelok); break;
        case 61: kanandikitK3(sudutBelok); break;
        case 62: kanancepatK3(sudutBelok); break;
        case 63: majudikitK3(sudutBelok); break;
        case 64: mundurdikitK3(sudutBelok); break;
        case 65: grabK3(); break;
        case 66: maju(30, 17, 6, 4, 15, longStep); break;
        case 67: Yaw20(); break;
        case 68: Yaw_20(); break;
        case 69: Inhale(); break;
        case 70: Exhale(); break;
        case 71: Pitch10(); break;
        case 72: Pitch_10(); break;
        case 99: standby(); break;
      }
      vTaskDelay(5 / portTICK_PERIOD_MS);
    }
  }
}

void sensor(void *pvParameters) {
  while (1) {
    //    readIRRange_0();
    //    vTaskDelay(300 / portTICK_PERIOD_MS);
    //    readIRRange_4();
    //    vTaskDelay(300 / portTICK_PERIOD_MS);
    //    readIRRange_2();
    //    vTaskDelay(300 / portTICK_PERIOD_MS);
    //                            readIRRange_6();
    //                            vTaskDelay(300 / portTICK_PERIOD_MS);
    //    DeteksiKorban3();
    //    DeteksiKorban1();
    //    readIRRange_4();
    //    readIRRange_0();
    //    readIRRange_2();
    TestRotJarak();
    //    while (turun) {
    //      command("turun_capit", 11, true);
    //      command("kosong", 35, false);
    //      vTaskDelay(100 / portTICK_PERIOD_MS); //40
    //      turun = false;
    //    }
    //    ReadPING_1();
    //     //      naiktangga();
    //                  Baca_kompas();
    //                readPitch();
  }
}
