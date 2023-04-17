#include "../include/microfx/microfx.h"

/******* Time *******/

/* Syscalls */

void _Sleep(int delay_ms);
int _RTC_GetTicks(void);
int _RTC_Elapsed_ms(int start_value, int duration_in_ms);
void _RTC_Reset(unsigned int mode);

int _Timer_Install(int InternalTimerID, void (*handler)(void), int elapse);
int _Timer_Deinstall(int InternalTimerID);
int _Timer_Start(int InternalTimerID);
int _Timer_Stop(int InternalTimerID);

/* Microfx */

void tsleep_ms(int ms) {
	_Sleep(ms);
}

int tgetticks(void) {
	return _RTC_GetTicks();
}

int tiselapsed(int start, int ms) {
	return _RTC_Elapsed_ms(start, ms);
}

void treset(void) {
	_RTC_Reset(1);
}

int tinittimer(int ms, void (*callback)(void)) {
	return _Timer_Install(0, callback, ms);
}

void tfreetimer(int id) {
	_Timer_Deinstall(id);
}

void tstarttimer(int id) {
	_Timer_Start(id);
}

void tstoptimer(int id) {
	_Timer_Stop(id);
}
