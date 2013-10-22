#pragma once
class vector_float
{
public:
	vector_float(void);
	~vector_float(void);
	void set(int value, int index);
	void read_from_keyboard();
	void print();

private:
	void create_vector(int s);
	void delete_vector();
};

