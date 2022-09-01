// MAX31856 adc driver of the Teensy4.1 kit
//
// Copyright (C) 2022 Unastella.co
// gwangho.seok@unastella.co
//

#include <MAX31856.h>
#include <Streaming.h>

MAX31856 tc1(10);	// CS pin

int main(void)
{
	Serial.begin(115200);
	//Serial << F( "\n" __FILE__ " " __DATE__ " " __TIME__ "\n" );
	delay(1000);

	tc1.begin();
	tc1.dumpRegs();
	tc1.setAvgSel(MAX31856::AVG4);
	tc1.setCR0(_BV(MAX31856::CR0_CMODE) | _BV(MAX31856::CR0_OCFAULT0));
	tc1.setMASK(0);     // unmask all faults
	tc1.write();
	tc1.read();
	tc1.dumpRegs();

	//Serial << F("CJ Fault  ") << tc1.getCJHF_C() << F("C ") << tc1.getCJHF_F() << F("F  ");
	//Serial << tc1.getCJLF_C() << F("C ") << tc1.getCJLF_F() << F("F\n");
	//Serial << F("TC Fault  ") << tc1.getLTHFT_C() << F("C ") << tc1.getLTHFT_F() << F("F  ");
	//Serial << tc1.getLTLFT_C() << F("C ") << tc1.getLTLFT_F() << F("F\n");
	//Serial << F("CJ Offset ") << tc1.getCJTO_C() << F("C ") << tc1.getCJTO_F() << F("F\n");

	while(1) {
		delay(1000);
		tc1.read();
		Serial << endl;
		tc1.dumpRegs();
		//Serial << F("CJ Temp ") << tc1.getCJT_C() << F("C ") << tc1.getCJT_F() << F("F\n");
		//Serial << F("TC Temp ") << tc1.getLTCT_C() << F("C ") << tc1.getLTCT_F() << F("F\n");
	}
}


