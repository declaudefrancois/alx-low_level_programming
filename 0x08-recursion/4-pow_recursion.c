/**
 * _pow_recursion - power with recursion
 * @x: the base
 * @y: the exposant
 *
 * Return: x^y
 */
int _pow_recursion(int x, int y)
{
	if (y == 0)
		return (1);
	if (y < 0)
		return (-1);

	return (x * _pow_recursion(x, y - 1));
}
