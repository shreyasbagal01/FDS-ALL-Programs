""" Assignment No -15  -Write a Python program to store second year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using
a)	Insertion sort
b)	Shell Sort and display top five scores
"""


def InsertSort(arr, n):
    for i in range(1, n):
        temp = arr[i]
        j = i-1
        while (j>=0 and temp< arr[j]):
            arr[j+1] = arr[j]
            j = j- 1
        arr[j+1] = temp
    print(arr)


def ShellSort(arr, n):
    gap = n // 2
    while(gap>=1):
        for j in range(gap, n):
            i=j-gap
            while (i>=0):
                if arr[i+gap]>arr[i]:
                    break
                else:
                    arr[i+gap], arr[i] = arr[i], arr[i+gap]
                i=i-gap
        gap = gap // 2
    print(arr)
    print("Top Five Scores are...")
    for i in range(n- 1, n- 6, -1):
        print(arr[i])


# Driver Code
print("\nHow many students are there?")
n = int(input())
array = []
i = 0
for i in range(n):
    print("\n Enter percentage marks")
    item = float(input())
    array.append(item)

print("You have entered following scores...\n")
print(array)


while True:
    print("Main Menu    \n 1. Insertion Sort\n 2. Shell Sort \n 3. Exit")
    print("\n Enter your Choice: ")
    choice = int(input())
    if (choice == 1):
        print("\n The sorted Scores are...")
        InsertSort(array, n)

    elif choice == 2:
        print("\n The sorted Scores are...")
        ShellSort(array, n)

    elif choice == 3:
        print("Thanks for using this program!")
        break

    else:
        print('\nPlease enter a valid choice')





