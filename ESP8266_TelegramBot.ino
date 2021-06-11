#include "CTBot.h"

CTBot myBot;
String ssid  = "test1";
String pass  = "putra146";
String token = "1693110941:AAFP39dwBKnBTRaMStq0whewAJFq1bsddYU";
int Data;
char c;
void setup()
{
  Serial.begin(9600);
  
  Serial.println("\nStarting TelegramBot...");
  Serial.print("Menyambungkan ke : ");
  Serial.println(ssid);
  myBot.wifiConnect(ssid, pass);
  myBot.setTelegramToken(token);

  if (myBot.testConnection())
  {
    Serial.print("Terhubung dengan : ");
    Serial.println(ssid);
  }
  else
  {
    Serial.println("\nError.");
  }
}

void loop()  
{
   TBMessage msg;
   if (myBot.getNewMessage(msg))
       {
         if (msg.text.equalsIgnoreCase("/cek_kondisi_tambak"))
             {
               Serial.println("Mengirim pesan ke Telegram");
               dataSerial();
                if (Data == 49) {
                     String welcome = "Kondisi Air Pada Tambak Saat ini Tercukupi Air.\n( Tinggi Air > 80% ).\n";
                     myBot.sendMessage(msg.group.id, welcome);
                 }
                   else if (Data== 50) {
                   String welcome = "Kondisi Air Pada Tambak Saat ini Tercukupi Air.\n( Tinggi Air 20% - 80% ).\n";
                   myBot.sendMessage(msg.group.id, welcome);
                   }
                     else if (Data == 51) {
                     String welcome = "Kondisi Air Pada Tambak Saat ini Kekurangan Air.\n( Tinggi Air < 20% ).\nPINTU AIR TERBUKA!!! .\nAIR MENGALIR!!!.\n";
                     myBot.sendMessage(msg.group.id, welcome);
                    }
                      else if (Data == 52) {
                      String welcome = "Kondisi Air Pada Tambak Saat ini Kekurangan Air.\n( Tinggi Air < 20% ).\nPINTU AIR TERBUKA!!!.\n "+ 
                                                   (String) "TIDAK AIR MENGALIR!!! (Penampung Air Koseong).\n";
                      myBot.sendMessage(msg.group.id, welcome);
                      }
                       
                }
                 else if (msg.text.equalsIgnoreCase("/start"))
                  {
                    Serial.println("Mengirim pesan ke Telegram...");
                  
                     String balasan;
                     balasan = (String)"Selamat Datang " + (String) "diBot Monitoring Ketimggiam Air Tambak Ikan" + (String)".\n" +
                                    (String)"/cek_kondisi_tambak : mengecek kondisi saat ini.";
                        myBot.sendMessage(msg.group.id, balasan);
                  }
                  else
                  {
                    Serial.println("Mengirim pesan ke Telegram...");
                    String balasan;
                    balasan = (String)"Pesan tidak ada!\n" +
                                   (String)"Silahkan cek kembali dengan\n" +
                                   (String)"mengirim pesan /start.";
                        myBot.sendMessage(msg.group.id, balasan);
                  }
                }
}

void dataSerial(){
  
  while(Serial.available()>0) 
      {
        delay(10);
        c = Serial.read();
        Data = c;
        Serial.println (Data);
      } 
}
