void Pitch(float pitch, float delays) {
  pitch = pitch / 180 * M_PI;
  Serial.print("Sudut Pitch :");
  Serial.println(pitch);
  float rotPitch[3][3] = {{cos(pitch), 0, sin(pitch)},
    {0, 1, 0},
    { -sin(pitch), 0, cos(pitch)}
  };
  float pitchFL[3][1] = {{0}, {0}, {0}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 1; j++) {
      for (int k = 0; k < 3; k++) {
        pitchFL[i][j] += rotPitch[i][k] * standFL[k][j];
      }
    }
  }
  float pitchFR[3][1] = {{0}, {0}, {0}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 1; j++) {
      for (int k = 0; k < 3; k++) {
        pitchFR[i][j] += rotPitch[i][k] * standFR[k][j];
      }
    }
  }
  float pitchBR[3][1] = {{0}, {0}, {0}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 1; j++) {
      for (int k = 0; k < 3; k++) {
        pitchBR[i][j] += rotPitch[i][k] * standBR[k][j];
      }
    }
  }
  float pitchBL[3][1] = {{0}, {0}, {0}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 1; j++) {
      for (int k = 0; k < 3; k++) {
        pitchBL[i][j] += rotPitch[i][k] * standBL[k][j];
      }
    }
  }
  xFL = pitchFL[0][0] - (-(Xoffset));
  yFL = pitchFL[1][0] - Yoffset;
  zFL = pitchFL[2][0];
  xFR = pitchFR[0][0] - Xoffset;
  yFR = pitchFR[1][0] - Yoffset;
  zFR = pitchFR[2][0];
  xBR = pitchBR[0][0] - Xoffset;
  yBR = pitchBR[1][0] - (-(Yoffset));
  zBR = pitchBR[2][0];
  xBL = pitchBL[0][0] - (-(Xoffset));
  yBL = pitchBL[1][0] - (-(Yoffset));
  zBL = pitchBL[2][0];
  Serial.println("TITIK TUJUAN :");
  Serial.print("XFL :");
  Serial.println(xFL);
  Serial.print("YFL :");
  Serial.println(yFL);
  Serial.print("ZFL :");
  Serial.println(zFL);
  Serial.print("XFR :");
  Serial.println(xFR);
  Serial.print("YFR :");
  Serial.println(yFR);
  Serial.print("ZFR :");
  Serial.println(zFR);
  Serial.print("XBR :");
  Serial.println(xBR);
  Serial.print("YBR :");
  Serial.println(yBR);
  Serial.print("ZBR :");
  Serial.println(zBR);
  Serial.print("XBL :");
  Serial.println(xBL);
  Serial.print("YBL :");
  Serial.println(yBL);
  Serial.print("ZBL :");
  Serial.println(zBL);
}

void Yaw20() {
  xFL = 55;//85
  xFR = 55;//13
  xBR = 55;//85
  xBL = 55;//13
  yFL = 55;//85
  yFR = 55;//85
  yBR = 55;//13
  yBL = 55;//13
  for (int i = 1; i <= 50; i++) {
    FRAuto(xFR, yFR, -75);
    BLAuto(-(xBL), -(yBL), -75);
    FLAuto(-(xFL), yFL, -75);
    BRAuto(xBR, -(yBR), -75);
    xFL += 0.6;//85
    xFR -= 0.84;//13
    xBR += 0.6;//85
    xBL -= 0.84;//13
    yFL -= 0.84;//13
    yFR += 0.6;//85
    yBR -= 0.84;//13
    yBL += 0.6;//85
    delay(15);
  }
}

void Yaw_20() {
  xFL = 55;//13
  yFL = 55;//85
  xFR = 55;//85
  yFR = 55;//13
  xBR = 55;//13
  yBR = 55;//85
  xBL = 55;//85
  yBL = 55;//13
  for (int i = 1; i <= 50; i++) {
    FRAuto(xFR, yFR, -75);
    BLAuto(-(xBL), -(yBL), -75);
    FLAuto(-(xFL), yFL, -75);
    BRAuto(xBR, -(yBR), -75);
    xFL -= 0.84;//13
    yFL += 0.6;//85
    xFR += 0.6;//85
    yFR -= 0.84;//13
    xBR -= 0.84;//13
    yBR += 0.6;//85
    xBL += 0.6;//85
    yBL -= 0.84;//13
    delay(15);
  }
}

void Inhale() {
  float zH = 75;
  for (int i = 1; i <= 50; i++) {
    FRAuto(55, 55, -(zH));
    BLAuto(-55, -55, -(zH));
    FLAuto(-55, 55, -(zH));
    BRAuto(55, -55, -(zH));
    zH += 0.4;
    delay(20);
  }
}

void Exhale() {
  float zH = 95;
  for (int i = 1; i <= 50; i++) {
    FRAuto(55, 55, -(zH));
    BLAuto(-55, -55, -(zH));
    FLAuto(-55, 55, -(zH));
    BRAuto(55, -55, -(zH));
    zH -= 0.4;
    delay(20);
  }
}

void Pitch10() {
  //10/-10
  xFL = 67;//41
  zFL = 56;//92
  xFR = 41;//67
  zFR = 92;//56
  xBR = 41;//67
  zBR = 92;//56
  xBL = 67;//41
  zBL = 56;//92
  for (int i = 1; i <= 20; i++) {
    FRAuto(xFR, 55, -(zFR));
    BLAuto(-(xBL), -55, -(zBL));
    FLAuto(-(xFL), 55, -(zFL));
    BRAuto(xBR, -55, -(zBR));
    xFL -= 1.3;//41
    zFL += 1.8;//92
    xFR += 1.3;//67
    zFR -= 1.8;//56
    xBR += 1.3;//67
    zBR -= 1.8;//56
    xBL -= 1.3;//41
    zBL += 1.8;//92
    delay(30);
  }
}

void Pitch_10() {
  //10/-10
  xFL = 41;//67
  zFL = 92;//56
  xFR = 67;//41
  zFR = 56;//92
  xBR = 67;//41
  zBR = 56;//92
  xBL = 41;//67
  zBL = 92;//56
  for (int i = 1; i <= 20; i++) {
    FRAuto(xFR, 55, -(zFR));
    BLAuto(-(xBL), -55, -(zBL));
    FLAuto(-(xFL), 55, -(zFL));
    BRAuto(xBR, -55, -(zBR));
    xFL += 1.3;//67
    zFL -= 1.8;//56
    xFR -= 1.3;//41
    zFR += 1.8;//92
    xBR -= 1.3;//41
    zBR += 1.8;//92
    xBL += 1.3;//67
    zBL -= 1.8;//56
    delay(30);
  }
}
