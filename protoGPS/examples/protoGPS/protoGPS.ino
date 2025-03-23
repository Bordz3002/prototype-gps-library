#include <formatfloat.h>
#include <Adafruit_GPS.h>
#include <Adafruit_PMTK.h>
#include <NMEA_data.h>
#define GPSECHO false
class GPS {
  private:
    Adafruit_GPS gps;
    static constexpr int invalid_int=99;
    static constexpr float invalid_float=0.0000;
    static constexpr char invalid_char='I';
  public:
    GPS(HardwareSerial &serial) : gps(&serial) {}
    formatfloat formatter;
    int invalid_num(void){
      return invalid_int;
    }
    float invalid_flt(void){
      return invalid_float;
    }
    char invalid_chr(void){
      return invalid_char;
    }
    void begin(void) {
      gps.begin(9600);
      gps.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
      gps.sendCommand(PMTK_SET_NMEA_UPDATE_10HZ);
      delay(1000);
    }
    bool gps_access(void){
      char c=gps.read();
      if(GPSECHO){
        if(c){
          Serial.print(c);
        }
      }
      if(gps.newNMEAreceived()){
        if(!gps.parse(gps.lastNMEA())){
          return false;
        }
        else{
          if(!gps.fix){
            return false;
          }
          else{ return true;}
        }
      }
      else{ return false;}
    }
    int fix_quality(void){
      return [&]()->int{
        if(gps_access()!=true){ return invalid_num();}
        else{ return gps.fixquality;}
      }();
    }
    int satellites(void){
      return [&]()->int{
        if(gps_access()!=true){ return invalid_num();}
        else{ return gps.satellites;}
      }();
    }
    int hour(void){
      return [&]()->int{
        if(gps_access()!=true){ return invalid_num();}
        else{ return gps.hour;}
      }();
    }
    int minute(void){
      return [&]()->int{
        if(gps_access()!=true){ return invalid_num();}
        else{ return gps.minute;}
      }();
    }
    int day(void){
      return [&]()->int{
        if(gps_access()!=true){ return invalid_num();}
        else{ return gps.day;}
      }();
    }
    int month(void){
      return [&]()->int{
        if(gps_access()!=true){ return invalid_num();}
        else{ return gps.month;}
      }();
    }
    int year(int year_prefix){
      return [&]()->int{
        if(gps_access()!=true){ return invalid_num();}
        else{ String year_format=String(year_prefix)+String(gps.year); return year_format.toInt();}
      }();
    }
    char lat(void){
      return [&]()->char{
        if(gps_access()!=true){ return invalid_chr();}
        else{ return gps.lat;}
      }();
    }
    float latitude(void){
      return [&]()->float{
        if(gps_access()!=true){ return invalid_flt();}
        else{ return formatter.format(gps.latitude);}
      }();
    }
    char lon(void){
      return [&]()->char{
        if(gps_access()!=true){ return invalid_chr();}
        else{ return gps.lon;}
      }();
    }
    float longitude(void){
      return [&]()->float{
        if(gps_access()!=true){ return invalid_flt();}
        else{ return formatter.format(gps.longitude);}
      }();
    }
};
GPS gps(Serial1);
void setup() {
  Serial.begin(115200);
  gps.begin();
}
void loop() {
  Serial.print("day: ");
  Serial.println(gps.day());
  Serial.print("month: ");
  Serial.println(gps.month());
  Serial.print("year: ");
  Serial.println(gps.year(20);
  Serial.print("latitude: ");
  Serial.println(gps.latitude());
  Serial.print("longitude: ");
  Serial.println(gps.longitude());
  delay(2000);
}
