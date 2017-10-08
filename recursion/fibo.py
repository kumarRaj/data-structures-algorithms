def febo(element):
	result = []
	a = -1
	b = 1
	for x in range(0,element):
		c = a + b
		result.append(c)
		a = b
		b = c

	return result.pop()

print(febo(8))

def recursivefebo(element):
	if element == 0:
		return 0
	if element == 1 or element == 2:
		return 1
	return febo(element-1) + febo(element-2)

print(recursivefebo(8))