void glutKeyboardFunc(void (*func) (unsigned char key, int x, int y));

void processNormalKeys(unsigned char key, int x, int y) 
{

	if (key == 27)
		exit(0);
}

