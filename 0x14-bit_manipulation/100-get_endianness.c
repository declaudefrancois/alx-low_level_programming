/**
 * get_endianness - checks the endianness.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
	/**
	 * If big endian, stored as: 0000 0000 0000 00001
	 * If Little endian, stored as: 0001 0000 0000 0000
	 * In both cases we read from left to right, I.E the
	 * indexes goes from left (0) to right.
	 *
	 * The endianness is handled automatically, so when i is directly
	 * accessed, it will always be interpreted as: 0000 0000 0000 0001.
	 */
	int i = 1;

	/**
	 * We get the direct reference to the memory location
	 * of i, in order to access the binary value stored in the
	 * actual indianness.
	 */
	char *p = (char *)&i;


	/**
	 * Here we can confirm the indianness by printing the different bytes.
	 * unsigned long int j;
	 * for (j = 0; j < sizeof(int); j++)
	 * {
	 *      printf("%02X ", p[j]);
	 * }
	 * puts("");
	 */

	/**
	 * i is always: 0000 0000 0000 0001.
	 *
	 * If big endian, p points to the value: 0000 0000 0000 0001.
	 * Then p[0] = 0b00000000 = 0
	 *
	 * else p points to the value: 0001 0000 0000 0000
	 * Then p[0] = 0b00010000 = 16
	 */
	return (p[0] == 0 ? 0 : 1);
}
