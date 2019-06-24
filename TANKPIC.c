//#include <RF24.h>

#pragma orgall 0x1000
unsigned char aux[100],aux1[100],aux2[100];
unsigned int  x,y,bu;
char josue;

void interrupt()
{
    if(INTCON.TMR0IF==1){       // Incrementa somente quando existir o overflow do timer 0.
       // Recarrega o timer0.
       TMR0H = 0x85;           // Carrega o valor alto do n?mero 57723.
       TMR0L = 0x34;            // Carrega o valor baixo do numero 57723.
       INTCON.TMR0IF = 0;       // Limpa o flag de estouro do timer0 para uma nova contagem de tempo.
 //            UART1_Write_Text("TIMEEEER");
    }


//UART1_Write_Text("1");
   if(INT1IF_bit)
    {
    delay_ms(100);
 //  UART1_Write_Text("1");
       INTCON3.INT1IF = 0;
      RB4_bit = 0x01;   //Liga o LED verde
   //   aux2[6] = 'B';
    }
}

void main (void) org 0x1000
{
   UART1_Init(9600);
  ADCON1 = 0x0F;           // Configura todos os pinos A/D como I/
   TRISB.RB0 = 1;
  // TRISB.RB0 = 1;
 //  INTCON2.INTEDG1 = 1;    //aciona interrup??o por borda de descida
 //  INTCON.GIE = 1;
        T0CON = 0b10000110;
   TMR0L = 0x34;
   TMR0H = 0x85;
   INTCON.TMR0IE = 1;       // Habilita interrup??o do timer0.
   INTCON.TMR0IF = 0;       // Apaga flag de estouro do timer0, pois ? fundamental para a sinaliza??o do estouro.         // Habilita as interrup??es n?o-mascaradas.
 //  INTCON.PEIE = 1;
//   INTCON3.INT1IE = 1;
 //  INTCON3.INT1IF = 0;
   
   TRISB.RB4 = 0;
   PORTB.RB4 = 0;
   PWM1_Init(5000);
   PWM1_Start();
   PWM2_Init(5000);
   PWM2_Start();
   while(1)
   {
    x= ADC_Read(1);
    x*=0.249;
     y= ADC_Read(2);
     y*=0.249;

      IntToStr(y,aux);
      IntToStr(x,aux1);
    //  IntToStr(bu,aux2);
      aux[6] = 'Y';
      aux1[6] = 'X';
     // delay_ms(1000);
   //   UART1_Write_Text("0ASD");
     // UART1_Write_Text(aux2);
      delay_ms(500);
      UART1_Write_Text(aux);
      delay_ms(500);
      UART1_Write_Text(aux1);
     // UART1_Write_Text("1");
      PWM1_Set_Duty(x);
      PWM2_Set_Duty(y);
     // delay_ms(1000);
   }
}
