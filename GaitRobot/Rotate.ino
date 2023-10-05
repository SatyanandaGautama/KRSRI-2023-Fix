void Yaw_15fx(){
  xFL = 24;//13
  yFL = 79;//85
  xFR = 79;//85
  yFR = 24;//13
  xBR = 24;//13
  yBR = 79;//85
  xBL = 79;//85
  yBL = 24;//13
  FRAuto(xFR, yFR, -75);
  BLAuto(-(xBL), -(yBL), -75);
  FLAuto(-(xFL), yFL, -75);
  BRAuto(xBR, -(yBR), -75);
}

void pitch10() {
  xFL = 36;//96
  yFL = 79;//13
  zFL = 61;//50
  xFR = 64;//1
  yFR = 24;//85
  zFR = 96;//85
  xBR = 10;//70
  yBR = 79;//13
  zBR = 87;//97
  xBL = 90;//25
  yBL = 24;//85
  zBL = 51;//63
  FRAuto(xFR, yFR, -(zFR));
  BLAuto(-(xBL), -(yBL), -(zBL));
  FLAuto(-(xFL), yFL, -(zFL));
  BRAuto(xBR, -(yBR), -(zBR));
}

void Yaw15fx() {
  xFL = 79;//13
  yFL = 24;//85
  xFR = 24;//85
  yFR = 79;//13
  xBR = 79;//13
  yBR = 24;//85
  xBL = 24;//85
  yBL = 79;//13
  FRAuto(xFR, yFR, -75);
  BLAuto(-(xBL), -(yBL), -75);
  FLAuto(-(xFL), yFL, -75);
  BRAuto(xBR, -(yBR), -75);
}

void pitch_10() {
  xFL = 64;//96
  yFL = 24;//13
  zFL = 96;//50
  xFR = 36;//1
  yFR = 79;//85
  zFR = 61;//85
  xBR = 90;//70
  yBR = 24;//13
  zBR = 51;//97
  xBL = 10;//25
  yBL = 79;//85
  zBL = 87;//63
  FRAuto(xFR, yFR, -(zFR));
  BLAuto(-(xBL), -(yBL), -(zBL));
  FLAuto(-(xFL), yFL, -(zFL));
  BRAuto(xBR, -(yBR), -(zBR));
}

void rotRightKelereng(float sdt) { //Default 10 derajat
  movecounter++;
  if (movecounter == 1) {
    IKRot1(55, 55, 25, sdt);
    IKRot1(-55, -55, 25, sdt);
    IKRot1(-55, 55, 0, sdt);
    IKRot1(55, -55, 0, sdt);
    delay(tr);

    IKRot1(52.59, 57.41, 22.22, sdt);
    IKRot1(-52.59, -57.41, 22.22, sdt);
    IKRot1(-54.7, 55.3, 0, sdt);
    IKRot1(54.7, -55.3, 0, sdt);
    delay(tr);

    IKRot1(50.74, 59.26, 13.89, sdt);
    IKRot1(-50.74, -59.26, 13.89, sdt);
    IKRot1(-54.4, 55.6, 0, sdt);
    IKRot1(54.4, -55.6, 0, sdt);
    delay(tr);

    ///////////////////////////////////////////////////
    IKRot1(50.4, 59.6, 8.85, sdt);
    IKRot1(-50.4, -59.6, 8.85, sdt);
    IKRot1(-54.3, 55.7, 0, sdt);
    IKRot1(54.3, -55.7, 0, sdt);
    delay(tr);

    IKRot1(50.28, 59.72, 4.3, sdt);
    IKRot1(-50.28, -59.72, 4.3, sdt);
    IKRot1(-54.2, 55.8, 0, sdt);
    IKRot1(54.2, -55.8, 0, sdt);
    delay(tr);
    //////////////////////////////////////////////////

    IKRot1(50, 60, 0, sdt);
    IKRot1(-50, -60, 0, sdt);
    IKRot1(-54.1, 55.9, 0, sdt);
    IKRot1(54.1, -55.9, 0, sdt);
    delay(tr);
    ///////////////////////////////////////////////////
    IKRot1(50.11, 59.89, 0, sdt);
    IKRot1(-50.11, -59.89, 0, sdt);
    IKRot1(-53.99, 56.01, 0, sdt);
    IKRot1(53.99, -56.01, 0, sdt);
    delay(tr);

    IKRot1(50.43, 59.57, 0, sdt);
    IKRot1(-50.43, -59.57, 0, sdt);
    IKRot1(-53.67, 56.33, 0, sdt);
    IKRot1(53.67, -56.33, 0, sdt);
    delay(tr);

    IKRot1(50.89, 59.11, 0, sdt);
    IKRot1(-50.89, -59.11, 0, sdt);
    IKRot1(-53.21, 56.79, 0, sdt);
    IKRot1(53.21, -56.79, 0, sdt);
    delay(tr);

    IKRot1(51.44, 58.56, 0, sdt);
    IKRot1(-51.44, -58.56, 0, sdt);
    IKRot1(-52.66, 57.34, 0, sdt);
    IKRot1(52.66, -57.34, 0, sdt);
    delay(tr);

    IKRot1(52.05, 57.95, 0, sdt);
    IKRot1(-52.05, -57.95, 0, sdt);
    IKRot1(-52.05, 57.95, 0, sdt);
    IKRot1(52.05, -57.95, 0, sdt);
    delay(tr);

    IKRot1(52.66, 57.34, 0, sdt);
    IKRot1(-52.66, -57.34, 0, sdt);
    IKRot1(-51.44, 58.56, 0, sdt);
    IKRot1(51.44, -58.56, 0, sdt);
    delay(tr);

    IKRot1(53.21, 56.79, 0, sdt);
    IKRot1(-53.21, -56.79, 0, sdt);
    IKRot1(-50.89, 59.11, 0, sdt);
    IKRot1(50.89, -59.11, 0, sdt);
    delay(tr);

    IKRot1(53.67, 56.33, 0, sdt);
    IKRot1(-53.67, -56.33, 0, sdt);
    IKRot1(-50.43, 59.57, 0, sdt);
    IKRot1(50.43, -59.57, 0, sdt);
    delay(tr);

    IKRot1(53.99, 56.01, 0, sdt);
    IKRot1(-53.99, -56.01, 0, sdt);
    IKRot1(-50.11, 59.89, 0, sdt);
    IKRot1(50.11, -59.89, 0, sdt);
    delay(tr);

    ///////////////////////////////////////////////////////
    IKRot1(54.1, 55.9, 0, sdt);
    IKRot1(-54.1, -55.9, 0, sdt);
    IKRot1(-50, 60, 0, sdt);
    IKRot1(50, -60, 0, sdt);
    delay(tr);

    IKRot1(54.40, 55.60, 0, sdt);
    IKRot1(-54.40, -55.60, 0, sdt);
    IKRot1(-50.74, 59.26, 13.89, sdt);
    IKRot1(50.74, -59.26, 13.89, sdt);
    delay(tr);

    IKRot1(54.7, 55.3, 0, sdt);
    IKRot1(-54.7, -55.3, 0, sdt);
    IKRot1(-52.59, 57.41, 22.22, sdt);
    IKRot1(52.59, -57.41, 22.22, sdt);
    delay(tr);
  }
  else if (movecounter == 2) {
    IKRot1(55, 55, 0, sdt);
    IKRot1(-55, -55, 0, sdt);
    IKRot1(-55, 55, 25, sdt);
    IKRot1(55, -55, 25, sdt);
    delay(tr);

    IKRot1(55.3, 54.7, 0, sdt);
    IKRot1(-55.3, -54.7, 0, sdt);
    IKRot1(-57.41, 52.59, 22.22, sdt);
    IKRot1(57.41, -52.59, 22.22, sdt);
    delay(tr);

    IKRot1(55.6, 54.4, 0, sdt);
    IKRot1(-55.6, -54.4, 0, sdt);
    IKRot1(-59.26, 50.74, 13.89, sdt);
    IKRot1(59.26, -50.74, 13.89, sdt);
    delay(tr);
    //////////////////////////////////////////

    IKRot1(55.7, 54.3, 0, sdt);
    IKRot1(-55.7, -54.3, 0, sdt);
    IKRot1(-59.6, 50.4, 8.85, sdt);
    IKRot1(59.6, -50.4, 8.85, sdt);
    delay(tr);

    IKRot1(55.8, 54.2, 0, sdt);
    IKRot1(-55.8, -54.2, 0, sdt);
    IKRot1(-59.72, 50.28, 4.3, sdt);
    IKRot1(59.72, -50.28, 4.3, sdt);
    delay(tr);
    ///////////////////////////////////////////
    IKRot1(55.9, 54.1, 0, sdt);
    IKRot1(-55.9, -54.1, 0, sdt);
    IKRot1(-60, 50, 0, sdt);
    IKRot1(60, -50, 0, sdt);
    delay(tr);

    ////////////////////////////////////
    IKRot1(56.01, 53.99, 0, sdt);
    IKRot1(-56.01, -53.99, 0, sdt);
    IKRot1(-59.89, 50.11, 0, sdt);
    IKRot1(59.89, -50.11, 0, sdt);
    delay(tr);

    IKRot1(56.33, 53.67, 0, sdt);
    IKRot1(-56.33, -53.67, 0, sdt);
    IKRot1(-59.57, 50.43, 0, sdt);
    IKRot1(59.57, -50.43, 0, sdt);
    delay(tr);

    IKRot1(56.79, 53.21, 0, sdt);
    IKRot1(-56.79, -53.21, 0, sdt);
    IKRot1(-59.11, 50.89, 0, sdt);
    IKRot1(59.11, -50.89, 0, sdt);
    delay(tr);

    IKRot1(57.34, 52.66, 0, sdt);
    IKRot1(-57.34, -52.66, 0, sdt);
    IKRot1(-58.56, 51.44, 0, sdt);
    IKRot1(58.56, -51.44, 0, sdt);
    delay(tr);

    IKRot1(57.95, 52.05, 0, sdt);
    IKRot1(-57.95, -52.05, 0, sdt);
    IKRot1(-57.95, 52.05, 0, sdt);
    IKRot1(57.95, -52.05, 0, sdt);
    delay(tr);

    IKRot1(58.56, 51.44, 0, sdt);
    IKRot1(-58.56, -51.44, 0, sdt);
    IKRot1(-57.34, 52.66, 0, sdt);
    IKRot1(57.34, -52.66, 0, sdt);
    delay(tr);

    IKRot1(59.11, 50.89, 0, sdt);
    IKRot1(-59.11, -50.89, 0, sdt);
    IKRot1(-56.79, 53.21, 0, sdt);
    IKRot1(56.79, -53.21, 0, sdt);
    delay(tr);

    IKRot1(59.57, 50.43, 0, sdt);
    IKRot1(-59.57, -50.43, 0, sdt);
    IKRot1(-56.33, 53.67, 0, sdt);
    IKRot1(56.33, -53.67, 0, sdt);
    delay(tr);

    IKRot1(59.89, 50.11, 0, sdt);
    IKRot1(-59.89, -50.11, 0, sdt);
    IKRot1(-56.01, 53.99, 0, sdt);
    IKRot1(56.01, -53.99, 0, sdt);
    delay(tr);

    ///////////////////////////////////////////
    IKRot1(60, 50, 0, sdt);
    IKRot1(-60, -50, 0, sdt);
    IKRot1(-55.9, 54.1, 0, sdt);
    IKRot1(55.9, -54.1, 0, sdt);
    delay(tr);

    IKRot1(59.26, 50.74, 13.89, sdt);
    IKRot1(-59.26, -50.74, 13.89, sdt);
    IKRot1(-55.6, 54.4, 0, sdt);
    IKRot1(55.6, -54.4, 0, sdt);
    delay(tr);

    IKRot1(57.41, 52.59, 22.22, sdt);
    IKRot1(-57.41, -52.59, 22.22, sdt);
    IKRot1(-55.3, 54.7, 0, sdt);
    IKRot1(55.3, -54.7, 0, sdt);
    delay(tr);
    movecounter = 0;
  }
}

void rotLeftKelereng(float sdt) { //Default 10 derajat
  movecounter++;
  if (movecounter == 1) {
    IKRot1(55, -55, 0, sdt);
    IKRot1(-55, 55, 0, sdt);
    IKRot1(55, 55, 25, sdt);
    IKRot1(-55, -55, 25, sdt);
    delay(tr);
    /////////////////////Movecounter 1////////////////
    IKRot1(55.3, -54.7, 0, sdt);
    IKRot1(-55.3, 54.7, 0, sdt);
    IKRot1(57.41, 52.59, 22.22, sdt);
    IKRot1(-57.41, -52.59, 22.22, sdt);
    delay(tr);

    IKRot1(55.6, -54.4, 0, sdt);
    IKRot1(-55.6, 54.4, 0, sdt);
    IKRot1(59.26, 50.74, 13.89, sdt);
    IKRot1(-59.26, -50.74, 13.89, sdt);
    delay(tr);

    IKRot1(55.7, -54.3, 0, sdt);
    IKRot1(-55.7, 54.3, 0, sdt);
    IKRot1(59.6, 50.4, 8.85, sdt);
    IKRot1(-59.6, -50.4, 8.85, sdt);
    delay(tr);

    IKRot1(55.8, -54.2, 0, sdt);
    IKRot1(-55.8, 54.2, 0, sdt);
    IKRot1(59.72, 50.28, 4.3, sdt);
    IKRot1(-59.72, -50.28, 4.3, sdt);
    delay(tr);

    IKRot1(55.9, -54.1, 0, sdt);
    IKRot1(-55.9, 54.1, 0, sdt);
    IKRot1(60, 50, 0, sdt);
    IKRot1(-60, -50, 0, sdt);
    delay(tr);

    IKRot1(56.01, -53.99, 0, sdt);
    IKRot1(-56.01, 53.99, 0, sdt);
    IKRot1(59.89, 50.11, 0, sdt);
    IKRot1(-59.89, -50.11, 0, sdt);
    delay(tr);

    IKRot1(56.33, -53.67, 0, sdt);
    IKRot1(-56.33, 53.67, 0, sdt);
    IKRot1(59.57, 50.43, 0, sdt);
    IKRot1(-59.57, -50.43, 0, sdt);
    delay(tr);

    IKRot1(56.79, -53.21, 0, sdt);
    IKRot1(-56.79, 53.21, 0, sdt);
    IKRot1(59.11, 50.89, 0, sdt);
    IKRot1(-59.11, -50.89, 0, sdt);
    delay(tr);

    IKRot1(57.34, -52.66, 0, sdt);
    IKRot1(-57.34, 52.66, 0, sdt);
    IKRot1(58.56, 51.44, 0, sdt);
    IKRot1(-58.56, -51.44, 0, sdt);
    delay(tr);

    IKRot1(57.95, -52.05, 0, sdt);
    IKRot1(-57.95, 52.05, 0, sdt);
    IKRot1(57.95, 52.05, 0, sdt);
    IKRot1(-57.95, -52.05, 0, sdt);
    delay(tr);

    IKRot1(58.56, -51.44, 0, sdt);
    IKRot1(-58.56, 51.44, 0, sdt);
    IKRot1(57.34, 52.66, 0, sdt);
    IKRot1(-57.34, -52.66, 0, sdt);
    delay(tr);

    IKRot1(59.11, -50.89, 0, sdt);
    IKRot1(-59.11, 50.89, 0, sdt);
    IKRot1(56.79, 53.21, 0, sdt);
    IKRot1(-56.79, -53.21, 0, sdt);
    delay(tr);

    IKRot1(59.57, -50.43, 0, sdt);
    IKRot1(-59.57, 50.43, 0, sdt);
    IKRot1(56.33, 53.67, 0, sdt);
    IKRot1(-56.33, -53.67, 0, sdt);
    delay(tr);

    IKRot1(59.89, -50.11, 0, sdt);
    IKRot1(-59.89, 50.11, 0, sdt);
    IKRot1(56.01, 53.99, 0, sdt);
    IKRot1(-56.01, -53.99, 0, sdt);
    delay(tr);

    IKRot1(60, -50, 0, sdt);
    IKRot1(-60, 50, 0, sdt);
    IKRot1(55.9, 54.1, 0, sdt);
    IKRot1(-55.9, -54.1, 0, sdt);
    delay(tr);

    IKRot1(59.26, -50.74, 13.89, sdt);
    IKRot1(-59.26, 50.74, 13.89, sdt);
    IKRot1(55.6, 54.4, 0, sdt);
    IKRot1(-55.6, -54.4, 0, sdt);
    delay(tr);

    IKRot1(57.41, -52.59, 22.22, sdt);
    IKRot1(-57.41, 52.59, 22.22, sdt);
    IKRot1(55.3, 54.7, 0, sdt);
    IKRot1(-55.3, -54.7, 0, sdt);
    delay(tr);
    //////////////////////////////////////////////
  }
  else if (movecounter == 2) {
    IKRot1(55, -55, 25, sdt);
    IKRot1(-55, 55, 25, sdt);
    IKRot1(55, 55, 0, sdt);
    IKRot1(-55, -55, 0, sdt);
    delay(tr);
    //////////////////Movecounter 2////////////////////
    IKRot1(52.59, -57.41, 22.22, sdt);
    IKRot1(-52.59, 57.41, 22.22, sdt);
    IKRot1(54.7, 55.3, 0, sdt);
    IKRot1(-54.7, -55.3, 0, sdt);
    delay(tr);

    IKRot1(50.74, -59.26, 13.89, sdt);
    IKRot1(-50.74, 59.26, 13.89, sdt);
    IKRot1(54.4, 55.6, 0, sdt);
    IKRot1(-54.4, -55.6, 0, sdt);
    delay(tr);

    IKRot1(50.4, -59.6, 8.85, sdt);
    IKRot1(-50.4, 59.6, 8.85, sdt);
    IKRot1(54.3, 55.7, 0, sdt);
    IKRot1(-54.3, -55.7, 0, sdt);
    delay(tr);

    IKRot1(50.28, -59.72, 4.3, sdt);
    IKRot1(-50.28, 59.72, 4.3, sdt);
    IKRot1(54.2, 55.8, 0, sdt);
    IKRot1(-54.2, -55.8, 0, sdt);
    delay(tr);

    IKRot1(50, -60, 0, sdt);
    IKRot1(-50, 60, 0, sdt);
    IKRot1(54.1, 55.9, 0, sdt);
    IKRot1(-54.1, -55.9, 0, sdt);
    delay(tr);

    IKRot1(50.11, -59.89, 0, sdt);
    IKRot1(-50.11, 59.89, 0, sdt);
    IKRot1(53.99, 56.01, 0, sdt);
    IKRot1(-53.99, -56.01, 0, sdt);
    delay(tr);

    IKRot1(50.43, -59.57, 0, sdt);
    IKRot1(-50.43, 59.57, 0, sdt);
    IKRot1(53.67, 56.33, 0, sdt);
    IKRot1(-53.67, -56.33, 0, sdt);
    delay(tr);

    IKRot1(50.89, -59.11, 0, sdt);
    IKRot1(-50.89, 59.11, 0, sdt);
    IKRot1(53.21, 56.79, 0, sdt);
    IKRot1(-53.21, -56.79, 0, sdt);
    delay(tr);

    IKRot1(51.44, -58.56, 0, sdt);
    IKRot1(-51.44, 58.56, 0, sdt);
    IKRot1(52.66, 57.34, 0, sdt);
    IKRot1(-52.66, -57.34, 0, sdt);
    delay(tr);

    IKRot1(52.05, -57.95, 0, sdt);
    IKRot1(-52.05, 57.95, 0, sdt);
    IKRot1(52.05, 57.95, 0, sdt);
    IKRot1(-52.05, -57.95, 0, sdt);
    delay(tr);

    IKRot1(52.66, -57.34, 0, sdt);
    IKRot1(-52.66, 57.34, 0, sdt);
    IKRot1(51.44, 58.56, 0, sdt);
    IKRot1(-51.44, -58.56, 0, sdt);
    delay(tr);

    IKRot1(53.21, -56.79, 0, sdt);
    IKRot1(-53.21, 56.79, 0, sdt);
    IKRot1(50.89, 59.11, 0, sdt);
    IKRot1(-50.89, -59.11, 0, sdt);
    delay(tr);

    IKRot1(53.67, -56.33, 0, sdt);
    IKRot1(-53.67, 56.33, 0, sdt);
    IKRot1(50.43, 59.57, 0, sdt);
    IKRot1(-50.43, -59.57, 0, sdt);
    delay(tr);

    IKRot1(53.99, -56.01, 0, sdt);
    IKRot1(-53.99, 56.01, 0, sdt);
    IKRot1(50.11, 59.89, 0, sdt);
    IKRot1(-50.11, -59.89, 0, sdt);
    delay(tr);

    IKRot1(54.1, -55.9, 0, sdt);
    IKRot1(-54.1, 55.9, 0, sdt);
    IKRot1(50, 60, 0, sdt);
    IKRot1(-50, -60, 0, sdt);
    delay(tr);

    IKRot1(54.40, -55.60, 0, sdt);
    IKRot1(-54.40, 55.60, 0, sdt);
    IKRot1(50.74, 59.26, 13.89, sdt);
    IKRot1(-50.74, -59.26, 13.89, sdt);
    delay(tr);

    IKRot1(54.7, -55.3, 0, sdt);
    IKRot1(-54.7, 55.3, 0, sdt);
    IKRot1(52.59, 57.41, 22.22, sdt);
    IKRot1(-52.59, -57.41, 22.22, sdt);
    delay(tr);
    movecounter = 0;
  }
}

void rotRightKelereng1(float sdt) { //Default 10 derajat
  movecounter++;
  if (movecounter == 1) {
    IKRot1(55, 55, 25, sdt);
    IKRot1(-55, -55, 25, sdt);
    IKRot1(-55, 55, 0, sdt);
    IKRot1(55, -55, 0, sdt);
    delay(tr);

    ///////////////Taruh Dibawah//////////////////// move counter 2
    IKRot1(52.59, 57.41, 22.22, sdt);
    IKRot1(-52.59, -57.41, 22.22, sdt);
    IKRot1(-54.17, 55.83, 0, sdt);
    IKRot1(54.17, -55.83, 0, sdt);
    delay(tr);

    IKRot1(50.74, 59.26, 13.89, sdt);
    IKRot1(-50.74, -59.26, 13.89, sdt);
    IKRot1(-53.36, 56.64, 0, sdt);
    IKRot1(53.36, -56.64, 0, sdt);
    delay(tr);
    IKRot1(50, 60, 0, sdt);
    IKRot1(-50, -60, 0, sdt);
    IKRot1(-52.59, 57.41, 0, sdt);
    IKRot1(52.59, -57.41, 0, sdt);
    delay(tr);

    IKRot1(50.09, 59.91, 0, sdt);
    IKRot1(-50.09, -59.91, 0, sdt);
    IKRot1(-51.89, 58.11, 0, sdt);
    IKRot1(51.89, -58.11, 0, sdt);
    delay(tr);

    IKRot1(50.34, 59.66, 0, sdt);
    IKRot1(-50.34, -59.66, 0, sdt);
    IKRot1(-51.26, 58.74, 0, sdt);
    IKRot1(51.26, -58.74, 0, sdt);
    delay(tr);

    IKRot1(50.74, 59.26, 0, sdt);
    IKRot1(-50.74, -59.26, 0, sdt);
    IKRot1(-50.74, 59.26, 0, sdt);
    IKRot1(50.74, -59.26, 0, sdt);
    delay(tr);

    IKRot1(51.26, 58.74, 0, sdt);
    IKRot1(-51.26, -58.74, 0, sdt);
    IKRot1(-50.34, 59.66, 0, sdt);
    IKRot1(50.34, -59.66, 0, sdt);
    delay(tr);

    IKRot1(51.89, 58.11, 0, sdt);
    IKRot1(-51.89, -58.11, 0, sdt);
    IKRot1(-50.09, 59.91, 0, sdt);
    IKRot1(50.09, -59.91, 0, sdt);
    delay(tr);

    IKRot1(52.59, 57.41, 0, sdt);
    IKRot1(-52.59, -57.41, 0, sdt);
    IKRot1(-50, 60, 0, sdt);
    IKRot1(50, -60, 0, sdt);
    delay(tr);

    IKRot1(53.36, 56.64, 0, sdt);
    IKRot1(-53.36, -56.64, 0, sdt);
    IKRot1(-50.74, 59.26, 13.89, sdt);
    IKRot1(50.74, -59.26, 13.89, sdt);
    delay(tr);

    IKRot1(54.17, 55.83, 0, sdt);
    IKRot1(-54.17, -55.83, 0, sdt);
    IKRot1(-52.59, 57.41, 22.22, sdt);
    IKRot1(52.59, -57.41, 22.22, sdt);
    delay(tr);
    //////////////////////////////////////////////
  }
  else if (movecounter == 2) {
    IKRot1(55, 55, 0, sdt);
    IKRot1(-55, -55, 0, sdt);
    IKRot1(-55, 55, 25, sdt);
    IKRot1(55, -55, 25, sdt);
    delay(tr);

    /////////////////Bawa Ke Atas/////////////
    IKRot1(55.83, 54.17, 0, sdt);
    IKRot1(-55.83, -54.17, 0, sdt);
    IKRot1(-57.41, 52.59, 22.22, sdt);
    IKRot1(57.41, -52.59, 22.22, sdt);
    delay(tr);

    IKRot1(56.64, 53.36, 0, sdt);
    IKRot1(-56.64, -53.36, 0, sdt);
    IKRot1(-59.26, 50.74, 13.89, sdt);
    IKRot1(59.26, -50.74, 13.89, sdt);
    delay(tr);

    IKRot1(57.41, 52.59, 0, sdt);
    IKRot1(-57.41, -52.59, 0, sdt);
    IKRot1(-60, 50, 0, sdt);
    IKRot1(60, -50, 0, sdt);
    delay(tr);

    IKRot1(58.11, 51.89, 0, sdt);
    IKRot1(-58.11, -51.89, 0, sdt);
    IKRot1(-59.91, 50.09, 0, sdt);
    IKRot1(59.91, -50.09, 0, sdt);
    delay(tr);

    IKRot1(58.74, 51.26, 0, sdt);
    IKRot1(-58.74, -51.26, 0, sdt);
    IKRot1(-59.66, 50.34, 0, sdt);
    IKRot1(59.66, -50.34, 0, sdt);
    delay(tr);

    IKRot1(59.26, 50.74, 0, sdt);
    IKRot1(-59.26, -50.74, 0, sdt);
    IKRot1(-59.26, 50.74, 0, sdt);
    IKRot1(59.26, -50.74, 0, sdt);
    delay(tr);

    IKRot1(59.66, 50.34, 0, sdt);
    IKRot1(-59.66, -50.34, 0, sdt);
    IKRot1(-58.74, 51.26, 0, sdt);
    IKRot1(58.74, -51.26, 0, sdt);
    delay(tr);

    IKRot1(59.91, 50.09, 0, sdt);
    IKRot1(-59.91, -50.09, 0, sdt);
    IKRot1(-58.11, 51.89, 0, sdt);
    IKRot1(58.11, -51.89, 0, sdt);
    delay(tr);

    IKRot1(60, 50, 0, sdt);
    IKRot1(-60, -50, 0, sdt);
    IKRot1(-57.41, 52.59, 0, sdt);
    IKRot1(57.41, -52.59, 0, sdt);
    delay(tr);

    IKRot1(59.26, 50.74, 13.89, sdt);
    IKRot1(-59.26, -50.74, 13.89, sdt);
    IKRot1(-56.64, 53.36, 0, sdt);
    IKRot1(56.64, -53.36, 0, sdt);
    delay(tr);

    IKRot1(57.41, 52.59, 22.22, sdt);
    IKRot1(-57.41, -52.59, 22.22, sdt);
    IKRot1(-55.83, 54.17, 0, sdt);
    IKRot1(55.83, -54.17, 0, sdt);
    delay(tr);
    movecounter = 0;
    /////////////////////////////////////////////////////////
  }
}


void rotate(int sudut, float tinggi) {
  for (int i = 0; i <= 10; i++) {
    //sudutx = sudut*-1;    //dikali -1 karena arah putarnya kebalik wkwk
    //sudut(+) putar kanan, sudut(-) putar kiri

    IKRot(55, 55, 0);
    sudut1 =  sudut + sdtcoxa1  ;
    IKRot(-55, 55, 0);
    sudut2 = sudut + sdtcoxa2  ;
    IKRot(-55, -55, 0);
    sudut3 = sudut + sdtcoxa3  ;
    IKRot(55, -55, 0);
    sudut4 = sudut + sdtcoxa4 ;
    move_counter++;
    Serial2.print("tinggi");
    Serial2.println(tinggi);

    if (move_counter == 1) {
      IKRot(55, 55, tinggi);
      gerak(7, sdtcoxa1 );
      gerak(8, sdtfemur );
      gerak(9, sdttibia );
      Serial2.print("tinggi 1");
      Serial2.println(sdttibia);
      IKRot(-55, -55, tinggi);
      gerak(1, sdtcoxa3 );
      gerak(2, sdtfemur );
      gerak(3, sdttibia );
      Serial2.print("tinggi 2");
      Serial2.println(sdttibia);
      delay(rotdelay);

      gerak(7, sudut1);
      gerak(1, sudut3);

      delay(rotdelay);

      IKRot(55, 55, 0);
      gerak(8, sdtfemur );
      gerak(9, sdttibia );
      Serial2.print("tinggi 3");
      Serial2.println(sdttibia);
      IKRot(-55, -55, 0);
      gerak(2, sdtfemur );
      gerak(3, sdttibia );
      Serial2.print("tinggi 4");
      Serial2.println(sdttibia);
      delay(rotdelay);

      IKRot(-55, 55, tinggi);
      gerak(10, sdtcoxa2 );
      gerak(11, sdtfemur );
      gerak(12, sdttibia );
      Serial2.print("tinggi 5");
      Serial2.println(sdttibia);
      IKRot(55, -55, tinggi);
      gerak(4, sdtcoxa4 );
      gerak(5, sdtfemur );
      gerak(6, sdttibia );
      Serial2.print("tinggi 6");
      Serial2.println(sdttibia);
      IKRot(55, 55, tinggi);
      gerak(7, sdtcoxa1 );
      IKRot(-55, -55, tinggi);
      gerak(1, sdtcoxa3 );

      delay(rotdelay);
    }

    else if (move_counter == 2) {

      IKRot(-55, 55, tinggi);
      gerak(10, sdtcoxa2 );
      gerak(11, sdtfemur );
      gerak(12, sdttibia );
      Serial2.print("tinggi 7");
      Serial2.println(sdttibia);
      IKRot(55, -55, tinggi);
      gerak(4, sdtcoxa4 );
      gerak(5, sdtfemur );
      gerak(6, sdttibia );
      Serial2.print("tinggi 8");
      Serial2.println(sdttibia);
      delay(rotdelay);

      gerak(10, sudut2);
      gerak(4, sudut4);

      delay(rotdelay);

      IKRot(-55, 55, 0);
      gerak(11, sdtfemur );
      gerak(12, sdttibia );
      Serial2.print("tinggi 9");
      Serial2.println(sdttibia);
      IKRot(55, -55, 0);
      gerak(5, sdtfemur );
      gerak(6, sdttibia );
      Serial2.print("tinggi 10");
      Serial2.println(sdttibia);
      delay(rotdelay);

      IKRot(55, 55, tinggi);
      gerak(7, sdtcoxa1 );
      gerak(8, sdtfemur );
      gerak(9, sdttibia );
      Serial2.print("tinggi 11"); ///Nilai Nan
      Serial2.println(sdttibia);

      IKRot(-55, -55, tinggi);
      gerak(1, sdtcoxa3 );
      gerak(2, sdtfemur );
      gerak(3, sdttibia );
      Serial2.print("tinggi 12");
      Serial2.println(sdttibia);
      IKRot(-55, 55, tinggi);
      gerak(10, sdtcoxa2);
      IKRot(55, -55, tinggi);
      gerak(4, sdtcoxa4);

      delay(rotdelay);
      move_counter = 0;
    }
  }
}

void gerak(int id, float pos) {
  dxl.setGoalPosition(id, pos, UNIT_DEGREE);
}




//void rotate180(){
//for(int i = 0; i<= 10; i++){
//move_counter++;
//  if (move_counter == 1) {
//        IKRot155, 55, 0, 0);
//        IKRot1(-32.87, -70.5, 0,0);
//        IKRot1(-38.61, 66.48, 0, 0);
//        IKRot149.26, -59.02, 0, 0);
//        delay(td2);
//
//        IKRot154.24, 55.53, 0, 0);
//        IKRot1(-33.63, -69.97, 0,0);
//        IKRot1(-35.66, 68.54, 0, 0);
//        IKRot152.21, -56.96, 0,0);
//        delay(td2);
//
//        IKRot152.21, 56.96, 0, 0);
//        IKRot1(-35.66, -68.54, 0,0);
//        IKRot1(-33.63, 69.97, 0, 0);
//        IKRot154.24, -55.53, 0, 0);
//        delay(td2);


//        IKRot149.26, 59.02, 0, 0);
//        IKRot1(-38.61, -66.48, 0,0);
//        IKRot1(-32.87, 70.5, 0, 0);
//        IKRot155, -55, 0, 0);
//        delay(td2);
//
//        IKRot147.56, 60.21, 0, 0);
//        IKRot1(-40.31, -65.29, 0,0);
//        IKRot1(-34.51, 69.35, 19.44, 0);
//        IKRot153.36, -56.15, 19.44, 0);
//        delay(td2);
//
//        IKRot145.77, 61.46, 0, 0);
//        IKRot1(-42.10, -64.04, 0,0);
//        IKRot1(-38.61, 66.48, 31.11, 0);
//        IKRot149.26, -59.02, 31.11, 0);
//        delay(td2);
//
//        IKRot143.93, 62.75, 0, 0);
//        IKRot1(-43.93, -62.75, 0,0);
//        IKRot1(-43.93, 62.75, 35, 0);
//        IKRot143.93, -62.75, 35, 0);
//        delay(td2);
//
//        IKRot142.10, 64.04, 0, 0);
//        IKRot1(-45.77, -61.46, 0,0);
//        IKRot1(-49.26, 59.02, 31.11, 0);
//        IKRot138.61, -66.48, 31.11, 0);
//        delay(td2);
//
//        IKRot140.31, 65.29, 0, 0);
//        IKRot1(-47.56, -60.21, 0,0);
//        IKRot1(-53.36, 56.15, 19.44,0);
//        IKRot134.51, -69.35, 19.44, 0);
//        delay(td2);
//
//        IKRot138.61, 66.48, 0, 0);
//        IKRot1(-49.26, -59.02, 0,0);
//        IKRot1(-55, 55, 0,0);
//        IKRot132.87, -70.5, 0, 0);
//        delay(td2);
//  }
// else if (move_counter == 2) {
//
//        IKRot135.66, 68.54, 0, 0);
//        IKRot1(-52.21, -56.96, 0,0);
//        IKRot1(-54.24, 55.53, 0,0);
//        IKRot133.63, -69.97, 0, 0);
//        delay(td2);
//
//        IKRot133.63, 69.97, 0, 0);
//        IKRot1(-54.24, -55.53, 0,0);
//        IKRot1(-52.21, 56.96, 0,0);
//        IKRot135.66, -68.54, 0, 0);
//        delay(td2);
//
//        IKRot132.87, 70.5, 0, 0);
//        IKRot1(-55, -55, 0,0);
//        IKRot1(-49.26, 55, 0,0);
//        IKRot138.61, -55, 0, 0);
//        delay(td2);
//
//        IKRot134.51, 69.35, 19.44, 0);
//        IKRot1(-53.36, -56.15, 19.44,0);
//        IKRot1(-47.56, 60.21, 0,0);
//        IKRot140.31, -65.29, 0, 0);
//        delay(td2);
//
//        IKRot138.61, 66.48, 31.11, 0);
//        IKRot1(-49.26, -59.02, 31.11,0);
//        IKRot1(-45.77, 61.46, 0,0);
//        IKRot142.10, -64.04, 0, 0);
//        delay(td2);
//
//        IKRot143.93, 62.75, 35, 0);
//        IKRot1(-43.93, -62.75, 35,0);
//        IKRot1(-43.93, 62.75, 0,0);
//        IKRot143.93, -62.75, 0, 0);
//        delay(td2);
//
//        IKRot149.26, 59.02, 31.11, 0);
//        IKRot1(-38.61, -66.48, 31.11,0);
//        IKRot1(-42.10, 64.04, 0,0);
//        IKRot145.77, -61.46, 0, 0);
//        delay(td2);
//
//        IKRot153.36, 56.15, 19.44, 0);
//        IKRot1(-34.51, -69.35, 19.44,0);
//        IKRot1(-40.31, 65.29, 0,0);
//        IKRot147.56, -60.21, 0, 0);
//        delay(td2);
//
//    move_counter = 0;
//  }
// }
//}





//void cobarotate(IKRot1oat sdt){ //Default 10 derajat
//
//        IKRot1(50, 60, 0, sdt);
//        IKRot1(-50, -60, 0,sdt);
//        IKRot1(-57.41, 52.59, 0,sdt);
//        IKRot1(57.41, -52.59, 0,sdt);
//        delay(td1);
//
//        IKRot1(50.09, 59.91, 0, sdt);
//        IKRot1(-50.09, -59.91, 0,sdt);
//        IKRot1(-58.11, 51.89, 0, sdt);
//        IKRot1(58.11, -51.89, 0, sdt);
//        delay(td1);
//
//        IKRot1(50.34, 59.66, 0, sdt);
//        IKRot1(-50.34, -59.66, 0, sdt);
//        IKRot1(-58.74, 51.26, 0, sdt);
//        IKRot1(58.74, -51.26, 0, sdt);
//        delay(td1);
//
//        IKRot1(50.74, 59.26, 0, sdt);
//        IKRot1(-50.74, -59.26, 0, sdt);
//        IKRot1(-59.26, 50.74, 0, sdt);
//        IKRot1(59.26, -50.74, 0, sdt);
//        delay(td2);
//
//        IKRot1(51.26, 58.74, 0, sdt);
//        IKRot1(-51.26, -58.74, 0, sdt);
//        IKRot1(-59.66, 50.34, 0, sdt);
//        IKRot1(59.66, -50.34, 0, sdt);
//        delay(td2);
//
//        IKRot1(51.89, 58.11, 0, sdt);
//        IKRot1(-51.89, -58.11, 0, sdt);
//        IKRot1(-59.91, 50.09, 0, sdt);
//        IKRot1(59.91, -50.09, 0, sdt);
//        delay(td2);
//
//        IKRot1(52.59, 57.41, 0, sdt);
//        IKRot1(-52.59, -57.41, 0, sdt);
//        IKRot1(-60, 50, 0, sdt);
//        IKRot1(60, -50, 0, sdt);
//        delay(td2);
//
//        IKRot1(53.36, 56.64, 0, sdt);
//        IKRot1(-53.36, -56.64, 0,sdt);
//        IKRot1(-59.26, 50.74, 19.44, sdt);
//        IKRot1(59.26, -50.74, 19.44, sdt);
//        delay(td2);
//
//        IKRot1(54.17, 55.83, 0, sdt);
//        IKRot1(-54.17, -55.83, 0, sdt);
//        IKRot1(-57.41, 52.59, 31.11,sdt);
//        IKRot1(57.41, -52.59, 31.11,sdt);
//        delay(td2);
//////////////////////////////////////////////
//        IKRot1(55, 55, 0, sdt);
//        IKRot1(-55, -55, 0,sdt);
//        IKRot1(-55, 55, 35,sdt);
//        IKRot1(55, -55, 35, sdt);
//        delay(td2);
//
//        IKRot1(55.83, 54.17, 0, sdt);
//        IKRot1(-55.83, -54.17, 0, sdt);
//        IKRot1(-52.59, 57.41, 31.11,sdt);
//        IKRot1(52.59, -57.41, 31.11,sdt);
//        delay(td2);
//
//        IKRot1(56.64, 53.36, 0, sdt);
//        IKRot1(-56.64, -53.36, 0, sdt);
//        IKRot1(-50.74, 59.26, 19.44,sdt);
//        IKRot1(50.74, -59.26, 19.44,sdt);
//        delay(td2);
//
//        IKRot1(57.41, 52.59, 0, sdt);
//        IKRot1(-57.41, -52.59, 0, sdt);
//        IKRot1(-50, 60, 0,sdt);
//        IKRot1(50, -60, 0, sdt);
//        delay(td2);
//
//        IKRot1(58.11, 51.89, 0, sdt);
//        IKRot1(-58.11, -51.89, 0, sdt);
//        IKRot1(-50.09, 59.91, 0,sdt);
//        IKRot1(50.09, -59.91, 0,sdt);
//        delay(td2);
//
//        IKRot1(58.74, 51.26, 0, sdt);
//        IKRot1(-58.74, -51.26, 0, sdt);
//        IKRot1(-50.34, 59.66, 0,sdt);
//        IKRot1(50.34, -59.66, 0,sdt);
//        delay(td2);
//
//        IKRot1(59.26, 50.74, 0, sdt);
//        IKRot1(-59.26, -50.74, 0, sdt);
//        IKRot1(-50.74, 59.26, 0,sdt);
//        IKRot1(50.74, -59.26, 0,sdt);
//        delay(td2);
//
//        IKRot1(59.66, 50.34, 0, sdt);
//        IKRot1(-59.66, -50.34, 0, sdt);
//        IKRot1(-51.26, 58.74, 0,sdt);
//        IKRot1(51.26, -58.74, 0,sdt);
//        delay(td2);
//
//        IKRot1(59.91, 50.09, 0, sdt);
//        IKRot1(-59.91, -50.09, 0, sdt);
//        IKRot1(-51.89, 58.11, 0,sdt);
//        IKRot1(51.89, -58.11, 0,sdt);
//        delay(td2);
//
//        IKRot1(60, 50, 0, sdt);
//        IKRot1(-60, -50, 0, sdt);
//        IKRot1(-52.59, 57.41, 0,sdt);
//        IKRot1(52.59, -57.41, 0,sdt);
//        delay(td2);
//
//        IKRot1(59.26, 50.74, 19.44, sdt);
//        IKRot1(-59.26, -50.74, 19.44,sdt);
//        IKRot1(-53.36, 56.64, 0,sdt);
//        IKRot1(53.36, -56.64, 0,sdt);
//        delay(td2);
//
//        IKRot1(57.41, 52.59, 31.11, sdt);
//        IKRot1(-57.41, -52.59, 31.11, sdt);
//        IKRot1(-54.17, 55.83, 0,sdt);
//        IKRot1(54.17, -55.83, 0,sdt);
//        delay(td2);
//
//        IKRot1(55, 55, 35, sdt);
//        IKRot1(-55, -55, 35,sdt);
//        IKRot1(-55, 55, 0,sdt);
//        IKRot1(55, -55, 0, sdt);
//        delay(td1);
//
//        IKRot1(52.59, 57.41, 31.11, sdt);
//        IKRot1(-52.59, -57.41, 31.11,sdt);
//        IKRot1(-55.83, 54.17, 0,sdt);
//        IKRot1(55.83, -54.17, 0,sdt);
//        delay(td1);
//
//        IKRot1(50.74, 59.26, 19.44, sdt);
//        IKRot1(-50.74, -59.26, 19.44,sdt);
//        IKRot1(-56.64, 53.36, 0,sdt);
//        IKRot1(56.64, -53.36, 0,sdt);
//        delay(td1);
//}


void rotateBatu(float sdt) { //Default 10 derajat

  IKRot1(55, 55, 35, sdt);
  IKRot1(-55, -55, 35, sdt);
  IKRot1(-55, 55, 0, sdt);
  IKRot1(55, -55, 0, sdt);
  delay(td1);

  IKRot1(52.59, 57.41, 31.11, sdt);
  IKRot1(-52.59, -57.41, 31.11, sdt);
  IKRot1(-54.17, 55.83, 0, sdt);
  IKRot1(54.17, -55.83, 0, sdt);
  delay(td1);

  IKRot1(50.74, 59.26, 19.44, sdt);
  IKRot1(-50.74, -59.26, 19.44, sdt);
  IKRot1(-53.36, 56.64, 0, sdt);
  IKRot1(53.36, -56.64, 0, sdt);
  delay(td1);
  IKRot1(50, 60, 0, sdt);
  IKRot1(-50, -60, 0, sdt);
  IKRot1(-52.59, 57.41, 0, sdt);
  IKRot1(52.59, -57.41, 0, sdt);
  delay(td1);

  IKRot1(50.09, 59.91, 0, sdt);
  IKRot1(-50.09, -59.91, 0, sdt);
  IKRot1(-51.89, 58.11, 0, sdt);
  IKRot1(51.89, -58.11, 0, sdt);
  delay(td1);

  IKRot1(50.34, 59.66, 0, sdt);
  IKRot1(-50.34, -59.66, 0, sdt);
  IKRot1(-51.26, 58.74, 0, sdt);
  IKRot1(51.26, -58.74, 0, sdt);
  delay(td1);

  IKRot1(50.74, 59.26, 0, sdt);
  IKRot1(-50.74, -59.26, 0, sdt);
  IKRot1(-50.74, 59.26, 0, sdt);
  IKRot1(50.74, -59.26, 0, sdt);
  delay(td2);

  IKRot1(51.26, 58.74, 0, sdt);
  IKRot1(-51.26, -58.74, 0, sdt);
  IKRot1(-50.34, 59.66, 0, sdt);
  IKRot1(50.34, -59.66, 0, sdt);
  delay(td2);

  IKRot1(51.89, 58.11, 0, sdt);
  IKRot1(-51.89, -58.11, 0, sdt);
  IKRot1(-50.09, 59.91, 0, sdt);
  IKRot1(50.09, -59.91, 0, sdt);
  delay(td2);

  IKRot1(52.59, 57.41, 0, sdt);
  IKRot1(-52.59, -57.41, 0, sdt);
  IKRot1(-50, 60, 0, sdt);
  IKRot1(50, -60, 0, sdt);
  delay(td2);

  IKRot1(53.36, 56.64, 0, sdt);
  IKRot1(-53.36, -56.64, 0, sdt);
  IKRot1(-50.74, 59.26, 19.44, sdt);
  IKRot1(50.74, -59.26, 19.44, sdt);
  delay(td2);

  IKRot1(54.17, 55.83, 0, sdt);
  IKRot1(-54.17, -55.83, 0, sdt);
  IKRot1(-52.59, 57.41, 31.11, sdt);
  IKRot1(52.59, -57.41, 31.11, sdt);
  delay(td2);
  ////////////////////////////////////////////
  IKRot1(55, 55, 0, sdt);
  IKRot1(-55, -55, 0, sdt);
  IKRot1(-55, 55, 35, sdt);
  IKRot1(55, -55, 35, sdt);
  delay(td2);

  IKRot1(55.83, 54.17, 0, sdt);
  IKRot1(-55.83, -54.17, 0, sdt);
  IKRot1(-57.41, 52.59, 31.11, sdt);
  IKRot1(57.41, -52.59, 31.11, sdt);
  delay(td2);

  IKRot1(56.64, 53.36, 0, sdt);
  IKRot1(-56.64, -53.36, 0, sdt);
  IKRot1(-59.26, 50.74, 19.44, sdt);
  IKRot1(59.26, -50.74, 19.44, sdt);
  delay(td2);

  IKRot1(57.41, 52.59, 0, sdt);
  IKRot1(-57.41, -52.59, 0, sdt);
  IKRot1(-60, 50, 0, sdt);
  IKRot1(60, -50, 0, sdt);
  delay(td2);

  IKRot1(58.11, 51.89, 0, sdt);
  IKRot1(-58.11, -51.89, 0, sdt);
  IKRot1(-59.91, 50.09, 0, sdt);
  IKRot1(59.91, -50.09, 0, sdt);
  delay(td2);

  IKRot1(58.74, 51.26, 0, sdt);
  IKRot1(-58.74, -51.26, 0, sdt);
  IKRot1(-59.66, 50.34, 0, sdt);
  IKRot1(59.66, -50.34, 0, sdt);
  delay(td2);

  IKRot1(59.26, 50.74, 0, sdt);
  IKRot1(-59.26, -50.74, 0, sdt);
  IKRot1(-59.26, 50.74, 0, sdt);
  IKRot1(59.26, -50.74, 0, sdt);
  delay(td2);

  IKRot1(59.66, 50.34, 0, sdt);
  IKRot1(-59.66, -50.34, 0, sdt);
  IKRot1(-58.74, 51.26, 0, sdt);
  IKRot1(58.74, -51.26, 0, sdt);
  delay(td2);

  IKRot1(59.91, 50.09, 0, sdt);
  IKRot1(-59.91, -50.09, 0, sdt);
  IKRot1(-58.11, 51.89, 0, sdt);
  IKRot1(58.11, -51.89, 0, sdt);
  delay(td2);

  IKRot1(60, 50, 0, sdt);
  IKRot1(-60, -50, 0, sdt);
  IKRot1(-57.41, 52.59, 0, sdt);
  IKRot1(57.41, -52.59, 0, sdt);
  delay(td2);

  IKRot1(59.26, 50.74, 19.44, sdt);
  IKRot1(-59.26, -50.74, 19.44, sdt);
  IKRot1(-56.64, 53.36, 0, sdt);
  IKRot1(56.64, -53.36, 0, sdt);
  delay(td2);

  IKRot1(57.41, 52.59, 31.11, sdt);
  IKRot1(-57.41, -52.59, 31.11, sdt);
  IKRot1(-55.83, 54.17, 0, sdt);
  IKRot1(55.83, -54.17, 0, sdt);
  delay(td2);
}

void rotatePecah1(float sdt) { //Default 10 derajat, delay = 27

  IKRot1(55, 55, 20, sdt);
  IKRot1(-55, -55, 20, sdt);
  IKRot1(-55, 55, 0, sdt);
  IKRot1(55, -55, 0, sdt);
  delay(td1);

  IKRot1(52.59, 57.41, 17.78, sdt);
  IKRot1(-52.59, -57.41, 17.78, sdt);
  IKRot1(-54.17, 55.83, 0, sdt);
  IKRot1(54.17, -55.83, 0, sdt);
  delay(td1);

  IKRot1(50.74, 59.26, 11.11, sdt);
  IKRot1(-50.74, -59.26, 11.11, sdt);
  IKRot1(-53.36, 56.64, 0, sdt);
  IKRot1(53.36, -56.64, 0, sdt);
  delay(td1);

  IKRot1(50, 60, 0, sdt);
  IKRot1(-50, -60, 0, sdt);
  IKRot1(-52.59, 57.41, 0, sdt);
  IKRot1(52.59, -57.41, 0, sdt);
  delay(td1);

  IKRot1(50.09, 59.91, 0, sdt);
  IKRot1(-50.09, -59.91, 0, sdt);
  IKRot1(-51.89, 58.11, 0, sdt);
  IKRot1(51.89, -58.11, 0, sdt);
  delay(td1);

  IKRot1(50.34, 59.66, 0, sdt);
  IKRot1(-50.34, -59.66, 0, sdt);
  IKRot1(-51.26, 58.74, 0, sdt);
  IKRot1(51.26, -58.74, 0, sdt);
  delay(td1);

  IKRot1(50.74, 59.26, 0, sdt);
  IKRot1(-50.74, -59.26, 0, sdt);
  IKRot1(-50.74, 59.26, 0, sdt);
  IKRot1(50.74, -59.26, 0, sdt);
  delay(td2);

  IKRot1(51.26, 58.74, 0, sdt);
  IKRot1(-51.26, -58.74, 0, sdt);
  IKRot1(-50.34, 59.66, 0, sdt);
  IKRot1(50.34, -59.66, 0, sdt);
  delay(td2);

  IKRot1(51.89, 58.11, 0, sdt);
  IKRot1(-51.89, -58.11, 0, sdt);
  IKRot1(-50.09, 59.91, 0, sdt);
  IKRot1(50.09, -59.91, 0, sdt);
  delay(td2);

  IKRot1(52.59, 57.41, 0, sdt);
  IKRot1(-52.59, -57.41, 0, sdt);
  IKRot1(-50, 60, 0, sdt);
  IKRot1(50, -60, 0, sdt);
  delay(td2);

  IKRot1(53.36, 56.64, 0, sdt);
  IKRot1(-53.36, -56.64, 0, sdt);
  IKRot1(-50.74, 59.26, 11.11, sdt);
  IKRot1(50.74, -59.26, 11.11, sdt);
  delay(td2);

  IKRot1(54.17, 55.83, 0, sdt);
  IKRot1(-54.17, -55.83, 0, sdt);
  IKRot1(-52.59, 57.41, 17.78, sdt);
  IKRot1(52.59, -57.41, 17.78, sdt);
  delay(td2);
  ////////////////////////////////////////////
  IKRot1(55, 55, 0, sdt);
  IKRot1(-55, -55, 0, sdt);
  IKRot1(-55, 55, 20, sdt);
  IKRot1(55, -55, 20, sdt);
  delay(td2);

  IKRot1(55.83, 54.17, 0, sdt);
  IKRot1(-55.83, -54.17, 0, sdt);
  IKRot1(-57.41, 52.59, 17.78, sdt);
  IKRot1(57.41, -52.59, 17.78, sdt);
  delay(td2);

  IKRot1(56.64, 53.36, 0, sdt);
  IKRot1(-56.64, -53.36, 0, sdt);
  IKRot1(-59.26, 50.74, 11.11, sdt);
  IKRot1(59.26, -50.74, 11.11, sdt);
  delay(td2);

  IKRot1(57.41, 52.59, 0, sdt);
  IKRot1(-57.41, -52.59, 0, sdt);
  IKRot1(-60, 50, 0, sdt);
  IKRot1(60, -50, 0, sdt);
  delay(td2);

  IKRot1(58.11, 51.89, 0, sdt);
  IKRot1(-58.11, -51.89, 0, sdt);
  IKRot1(-59.91, 50.09, 0, sdt);
  IKRot1(59.91, -50.09, 0, sdt);
  delay(td2);

  IKRot1(58.74, 51.26, 0, sdt);
  IKRot1(-58.74, -51.26, 0, sdt);
  IKRot1(-59.66, 50.34, 0, sdt);
  IKRot1(59.66, -50.34, 0, sdt);
  delay(td2);

  IKRot1(59.26, 50.74, 0, sdt);
  IKRot1(-59.26, -50.74, 0, sdt);
  IKRot1(-59.26, 50.74, 0, sdt);
  IKRot1(59.26, -50.74, 0, sdt);
  delay(td2);

  IKRot1(59.66, 50.34, 0, sdt);
  IKRot1(-59.66, -50.34, 0, sdt);
  IKRot1(-58.74, 51.26, 0, sdt);
  IKRot1(58.74, -51.26, 0, sdt);
  delay(td2);

  IKRot1(59.91, 50.09, 0, sdt);
  IKRot1(-59.91, -50.09, 0, sdt);
  IKRot1(-58.11, 51.89, 0, sdt);
  IKRot1(58.11, -51.89, 0, sdt);
  delay(td2);

  IKRot1(60, 50, 0, sdt);
  IKRot1(-60, -50, 0, sdt);
  IKRot1(-57.41, 52.59, 0, sdt);
  IKRot1(57.41, -52.59, 0, sdt);
  delay(td2);

  IKRot1(59.26, 50.74, 11.11, sdt);
  IKRot1(-59.26, -50.74, 11.11, sdt);
  IKRot1(-56.64, 53.36, 0, sdt);
  IKRot1(56.64, -53.36, 0, sdt);
  delay(td2);

  IKRot1(57.41, 52.59, 17.78, sdt);
  IKRot1(-57.41, -52.59, 17.78, sdt);
  IKRot1(-55.83, 54.17, 0, sdt);
  IKRot1(55.83, -54.17, 0, sdt);
  delay(td2);
}
