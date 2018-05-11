#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

typedef struct Constants {
  int tempo_sim = 1000;

  int N1sul_fonte_f = 20, N1sul_fonte_var = 5;
  int N1sul_fonte_v = 17, N1sul_fonte_s = 500;
  int N1sul_sumidouro_v = 17, N1sul_sumidouro_s = 500;

  int N2sul_fonte_f = 20, N2sul_fonte_var = 5;
  int N2sul_fonte_v = 11, N2sul_fonte_s 500;
  int N2sul_sumidouro_v = 11, N2sul_sumidouro_s = 500;

  int S1norte_fonte_f = 30, S1norte_fonte_var = 7;
  int S1norte_fonte_v = 17, S1norte_fonte_s = 500;
  int S1norte_sumidouro_v = 17, S1norte_sumidouro_s = 500;

  int S2norte_fonte_f = 60, S2norte_fonte_var = 15;
  int S2norte_fonte_v = 11, S2norte_fonte_s = 500;
  int S2norte_sumidouro_v = 11, S2norte_sumidouro_s = 500;
  //80/3.6 = 22
  //30/3.6 = 8
  int Oeste_fonte_f = 10, Oeste_fonte_var = 2;
  int Oeste_fonte_v = 22, Oeste_fonte_s = 2000;
  int Oeste_sumidouro_v = 22, Oeste_sumidouro_s = 2000;

  int Centro_fonte_v = 17, Centro_fonte_s = 300;
  int Centro_sumidouro_v = 17, Centro_sumidouro_s = 300;

  int Leste_fonte_f = 10, Leste_fonte_var = 2;
  int Leste_fonte_v = 17, Leste_fonte_s = 400;
  int Leste_sumidouro_v = 17, Leste_sumidouro_s = 400;

  //////////////////////////////////////////////////
  int S1_O_centro_leste = 80;
  int S1_O_norte_norte = 10;
  int S1_O_leste_sul = 10;

  int S1_N_centro_leste = 80;
  int S1_N_oeste_oeste = 10;
  int S1_N_sul_sul = 10;

  int S1_S_centro_leste = 80;
  int S1_S_norte_norte = 10;
  int S1_S_oeste_oeste = 10;

  int S1_C_oeste_oeste = 40;
  int S1_C_norte_norte = 30;
  int S1_C_sul_sul = 30;

  ///////

  int S2_C_leste_leste = 40;
  int S2_C_sul_sul = 30;
  int S2_C_norte_norte = 30;

  int S2_N_leste_leste = 40;
  int S2_N_centro_oeste = 30;
  int S2_N_sul_sul = 30;

  int S2_S_leste_leste = 40;
  int S2_S_leste_sul = 30;
  int S2_S_centro_oeste = 30;

  int S2_L_norte_norte = 40;
  int S2_L_centro_leste = 30;
  int S2_L_sul_sul = 30;

}Constants;

#endif
