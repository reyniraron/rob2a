task watchForStop() {
	while (true) {
		// RC button     // Touch sensor
		if (vexRT[Btn7L] || SensorValue(touchSensor)) {
			StopAllTasks();
		}
	}
}
