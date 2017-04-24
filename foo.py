N = int(input())
half = int(N / 2)
numbers = [int(x) for x in input().split(' ')]
sorted_numbers = sorted(numbers)
temp_d = dict()

for n in sorted_numbers:
    if n not in temp_d:
        temp_d[n] = 1
    else:
        temp_d[n] += 1

mean = sum(numbers) / N
median = (sorted_numbers[half-1] + sorted_numbers[half]) / 2    
mode = min(sorted(temp_d, key=temp_d.__getitem__, reverse=True))

print("{0}\n{1}\n{2}".format(mean, median, mode))

