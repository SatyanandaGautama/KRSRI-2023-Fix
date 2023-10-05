void ReadPING_1() {
  pinMode(PA6, OUTPUT);
  digitalWrite(PA6, LOW);
  delay(7);
  digitalWrite(PA6, HIGH);
  delay(7);
  digitalWrite(PA6, LOW);
  pinMode(PA6, INPUT);
  duration = pulseIn(PA6, HIGH);
  cm = duration / 29 / 2 ;
  jarak[0] = cm;
  DEBUG_SERIAL.print("PING 1 : ");
  DEBUG_SERIAL.println(jarak[0]);
}

void readIRRange_2() { //(IR KANAN)
  IRRangeVal_2 = vl53_2.distance();
  IRRangeVal_2 = IRRangeVal_2 / 10;
  vl53_2.clearInterrupt();
  if (IRRangeVal_2 == 0) {                         //karena batasan dari fungsi pulseIn, kalo sensor bilang 0, berarti jauh.
    IRRangeFuzzy_2 = 3;
  }
  else if (IRRangeVal_2 <= 1) {                         //jarak dekat
    IRRangeFuzzy_2 = 0;
  }
  else if (IRRangeVal_2 > 1 && IRRangeVal_2 <= 25) { //20
    IRRangeFuzzy_2 = 1;
  }

  else {
    IRRangeFuzzy_2 = 2;
  }
  DEBUG_SERIAL.print(F("IR KANAN: "));
  DEBUG_SERIAL.print(IRRangeVal_2);
  DEBUG_SERIAL.println(" cm");
  vTaskDelay(10 / portTICK_PERIOD_MS);
}

void readIRRange_6() {  //(IR KIRI)
  IRRangeVal_6 = vl53_6.distance();
  IRRangeVal_6 = IRRangeVal_6 / 10;
  vl53_6.clearInterrupt();

  if (IRRangeVal_6 == 0) {                         //karena batasan dari fungsi pulseIn, kalo sensor bilang 0, berarti jauh. ???
    IRRangeFuzzy_6 = 3;
  }
  else if (IRRangeVal_6 <= 1) {                         //jarak dekat
    IRRangeFuzzy_6 = 0;
  }
  else if (IRRangeVal_6 > 1 && IRRangeVal_6 <= 25) { //20
    IRRangeFuzzy_6 = 1;
  }
  else {
    IRRangeFuzzy_6 = 2;
  }

  //  DEBUG_SERIAL.print(F("IR KIRI : "));
  //  DEBUG_SERIAL.print(IRRangeVal_6);
  //  DEBUG_SERIAL.println(" cm");

  vTaskDelay(10 / portTICK_PERIOD_MS);
}

void readIRRange_0() {//IR DEPAN
  IRRangeVal_0 = vl53_0.distance();
  IRRangeVal_0 = IRRangeVal_0 / 10;
  vl53_0.clearInterrupt();
  /*--------SET FILTER-----------------*/
  filteredIR_0 = ((1 - filter_weight) * filteredIR_0) + (filter_weight * IRRangeVal_0);
  //  if (IRRangeVal_0 == 0) {                         //karena batasan dari fungsi pulseIn, kalo sensor bilang 0, berarti jauh.
  //    IRRangeFuzzy_0 = 3;
  //  }
  //  else if (IRRangeVal_0 <= 1) {                         //jarak dekat
  //    IRRangeFuzzy_0 = 0;
  //  }
  //  else if (IRRangeVal_0 > 1 && IRRangeVal_0 <= 25) { //20
  //    IRRangeFuzzy_0 = 1;
  //  }
  //  else {
  //    IRRangeFuzzy_0 = 2;
  //  }

  DEBUG_SERIAL.print(F("IR DEPAN : "));
  DEBUG_SERIAL.print(IRRangeVal_0);
  DEBUG_SERIAL.println(" cm");

  vTaskDelay(10 / portTICK_PERIOD_MS);
}

void readIRRange_4() { //IR Belakang
  IRRangeVal_4 = vl53_4.distance();
  IRRangeVal_4 = IRRangeVal_4 / 10;
  vl53_4.clearInterrupt();
  /*--------SET FILTER-----------------*/
  filteredIR_4 = ((1 - filter_weight) * filteredIR_4) + (filter_weight * IRRangeVal_4);
  //  if (IRRangeVal_4 == 0) {                         //karena batasan dari fungsi pulseIn, kalo sensor bilang 0, berarti jauh.
  //    IRRangeFuzzy_4 = 3;
  //  }
  //  else if (IRRangeVal_4 <= 5) {                         //jarak dekat
  //    IRRangeFuzzy_4 = 0;
  //  }
  //  else if (IRRangeVal_4 > 5 && IRRangeVal_4 <= 5) { //20
  //    IRRangeFuzzy_4 = 1;
  //  }
  //  else {
  //    IRRangeFuzzy_4 = 2;
  //  }
  DEBUG_SERIAL.print(F("IR BELAKANG : "));
  DEBUG_SERIAL.print(IRRangeVal_4);
  DEBUG_SERIAL.println(" cm");

  //  vTaskDelay(10 / portTICK_PERIOD_MS);
}
