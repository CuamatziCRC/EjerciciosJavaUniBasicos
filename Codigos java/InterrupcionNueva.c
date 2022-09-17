sbit LCD_RS at RD1_bit;
sbit LCD_EN at RD0_bit;
sbit LCD_RW at RD2_bit;
sbit LCD_D7 at RD7_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D4 at RD4_bit;

//Bits de configuración TRIS
sbit LCD_RS_Direction at TRISD1_bit;
sbit LCD_RW_Direction at TRISD2_bit;
sbit LCD_EN_Direction at TRISD0_bit;
sbit LCD_D7_Direction at TRISD7_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D4_Direction at TRISD4_bit;

char contador=0;
void interrupt(){
if(INTCON.F1==1){
//SI HAY UNA INTERRUPCION
contador++;
PORTB.RB2=0;
INTCON.F1=0;
}
}
void main() {

int porcentaje=0;
int a=0;
int orden = 0;
char cadena[10];
int aux=0;
int var=0;
int i=0;
int oper=0,oper2=0;
char conta[8];
INTCON.GIE=1;
INTCON.INTE=1;
TRISC = 0x00;//Declaramos com salida
PORTC = 1; //Inicializamos el puerto C
TRISD = 0x00;
PORTD = 0x00; //Utilizamos el puerto B como un puerto de Salida
TRISA = 0x00;   //Habilitamos el puerto B como salida.
PORTA = 1; //Utilizamos el puerto B como un puerto de Entrada
PWM1_Init(5000);            //Frecuencia PWM.
PWM1_Start();
Lcd_Init();
 TRISB.B2=0;
Lcd_Cmd (_LCD_CURSOR_OFF);
while(1){
PORTB.RB2=1;
if(var==1){
Lcd_Cmd (_LCD_CLEAR);
delay_ms(1000);
var=0;
}
Lcd_Cmd (_LCD_CURSOR_OFF);
         if (PORTC.RC7  ==1 && porcentaje<100){
          porcentaje=porcentaje+25;
          PWM1_Set_Duty(porcentaje*2.5);
          delay_ms(250);
          aux=aux+1;
          orden=0;
          }
          if(PORTC.RC6==1 && porcentaje>0){
           porcentaje=porcentaje-25;
           PWM1_Set_Duty(porcentaje-(porcentaje*2.5));
           delay_ms(250);
           var=0;
          }

          PWM1_Set_Duty((porcentaje*2.5));
          IntToStr(porcentaje,cadena);

         if (orden==0){
          orden=0;
          }
          if (porcentaje>80){
              PORTB.RB6 = 1;
              delay_ms(2);
              PORTB.RB6 = 0;
       }
       if (porcentaje>75 && porcentaje<=100){
       a=0;
       }
       if (porcentaje == 100){
       }
       if (porcentaje==80){
       }
       if (porcentaje==0 && aux>0)
       {
           aux=0;
           orden=orden+1;
           var=var+1;
       }

delay_ms(999);
Lcd_Out(1,1,"REVOLUCIONES/MIN");
oper=contador;
oper2=oper;
ByteToStr(oper2,conta);
Lcd_Out(2,1,conta);
Lcd_Out(2,7,"RPM");
for(i=0;i<10;i++){
conta[i]=' ';
}


contador=0;


}

}