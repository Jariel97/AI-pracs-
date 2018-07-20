with open('data.txt') as f:
	w, h = [int(x) for x in next(f).split()]
	array = [[int(x) for x in line.split()] for line in f]
	for i in range(0,9):	
		array.pop()
	array.pop(0)
	
	print(dict(array))

	
