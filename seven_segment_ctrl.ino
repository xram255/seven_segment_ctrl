#define SEG_DELAY 5

int8_t a = 1;
int8_t b = 1;

int8_t segment_num = 0;
uint8_t nums[11] = { 0x6F, 0x48, 0x3E, 0x5E, 0x59, 0x57, 0x77, 0x4C, 0x7F, 0x5F };

void setup()
{
	Serial.begin(9600);
	
	DDRL = 0xFF;
	DDRC = 0xFF;
	DDRA = 0xFF;

	PORTL = 0b00001111;
	PORTC = 0x7F;
	PORTA = 0;
	
}

void loop()
{
	segment_b(15);
	//Serial.println(numbers(0), HEX);
	/*
	segment_out(nums[7]);
	segment_ctrl(1);
	delay(5);

	segment_out(nums[8]);
	segment_ctrl(2);
	delay(5);
	*/
	/*
	segment_out(0x48);
	segment_ctrl(1);
	delay(1000);

	segment_out(0x3E);
	segment_ctrl(2);
	delay(1000);

	segment_out(0x5E);
	segment_ctrl(4);
	delay(1000);

	segment_out(0x59);
	segment_ctrl(8);
	delay(1000);

	segment_out(0x57);
	segment_ctrl(16);
	delay(1000);

	segment_out(0x77);
	segment_ctrl(32);
	delay(1000);

	segment_out(0x4C);
	segment_ctrl(1);
	delay(1000);

	segment_out(0x7F);
	segment_ctrl(2);
	delay(1000);

	segment_out(0x5F);
	segment_ctrl(4);
	delay(1000);

	segment_out(0x6F);
	segment_ctrl(8);
	delay(1000);
	*/
}

void segment_out(uint8_t inVal)
{
	uint8_t port_val = 0x7F & ~inVal;
	PORTC = port_val;
}

void segment_ctrl(uint8_t inVal)
{
	uint8_t port_val = 0x3F & inVal;
	PORTA = port_val;
}

void test_segments(uint16_t delay_t)
{
	for (int i = 1; i < 8; i++)
	{
		segment_out(a);
		a *= 2;
		delay(10);

		for (int j = 1; j < 8; j++)
		{
			segment_ctrl(b);
			b *= 2;
			delay(delay_t);
		}
		b = 1;
	}
}

void segment_b(uint8_t in_val)
{
	if (in_val > 99)
	{
		segment_out(nums[9]);
		segment_ctrl(2);
		delay(SEG_DELAY);

		segment_out(nums[9]);
		segment_ctrl(1);
		delay(SEG_DELAY);
	}
	else
	{
		segment_out(nums[in_val / 10]);
		segment_ctrl(2);
		delay(SEG_DELAY);

		segment_out(nums[in_val % 10]);
		segment_ctrl(1);
		delay(SEG_DELAY);
	}
}
