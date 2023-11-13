#include <graphics.h>
#include <iostream>
using namespace std;

int main() {
	initgraph(1000, 1000);
	int x = 500, y = 500;
	float z = 10;
	while (1) {
		ExMessage msg;
		if (peekmessage(&msg)) {
			if (msg.message == WM_MOUSEWHEEL) {
				z += msg.wheel / 120;
			}
			if (msg.message == WM_MOUSEMOVE) {
				x = msg.x;
				y = msg.y;
			}
		}
		if (z < 0) {
			z = 0;
		}
		cleardevice();
		solidcircle(x, y, z);
	}
	return 0;
}