import sys

x = sys.argv[1]

brackets = {'(':')',
		'[':']',
		'{':'}'}

bracketCount = {'(':0,
		'[':0,
		'{':0}

def getExpectation(input):
	return brackets.get(input, '');

stack = []
expectation = ""
for c in x:
	if c == expectation:
		stack.pop()
		if not stack:
			expectation = ""
		else:
			expectation = getExpectation(stack[len(stack) - 1])
	else:
		expectation = getExpectation(c);
		stack.append(c)

print stack