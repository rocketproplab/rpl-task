class TestTask : public RplTask {
	public:
		int i = 0; //tests if each method runs
	protected:
		void onStart() {i = 1;};
		void onResume() {i = 2;};
		void onPause() {i = 3;};
		void onLoop() {i = 4;};
}; 
