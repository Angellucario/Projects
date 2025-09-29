# Angel Lucario
# CSC 110
# Final Project - Airline Scheduling Program
# Dec 7 2024



# Project Description
# -------------------

# The Airline Scheduling Program is a simple and helpful tool for
# managing flight information. With this program, you can look up specific flight details,
# find flights that are shorter than a certain duration, check for the cheapest flights from an
# airline, and see flights that leave after a specific time. You can also calculate the average price of all flights and even save a sorted list of
# flights by departure time into a file. The program is designed to be userfriendly, with a nice menuand easy to follow choices.
# It handles errors, like wrong file names or invalid inputs, so you can focus on finding the information you need without frustration.
# Whether you're planning a trip or organizing flight schedules.




# this will oepn the file and will be able to handle files that are not found
def openFile():
    file = False
    while file == False:
        fname = input("Please enter a file name: ") # user input
        try:
            airlineFile = open(fname, 'r') # this will attempt to open the file
            file = True # sets to true if found
        except IOError:
            print("Invalid file name try again ...") #  handles the file if not found
    return airlineFile

# this is where we get all the file from the data 
def getData():
    airlineFile = openFile() # opens the file 

    # this will hold all of our flight data 

    airlineList = [] # airline name data 
    flightNumList = [] # flight numbers data 
    departTimeList = [] # depart time data
    arrivalTimeList = [] # arrival time data
    priceList = [] # price data

    # reads through each of the line in the file
    for line in airlineFile:
        line = line.strip() # removes white space
        airline, flightNum, departTime, arrivalTime, price = line.split(',') # splits the data
        # appends all of the data found in our file
        airlineList.append(str(airline))
        flightNumList.append(int(flightNum))
        departTimeList.append(str(departTime))
        arrivalTimeList.append(str(arrivalTime))
        priceList.append(float(price[1:])) # here we skip the $ symbol and only take the float digit

    airlineFile.close() # close the file

    return airlineList, flightNumList, departTimeList, arrivalTimeList, priceList

# Converts time from "HH:MM" format to total minutes
def timeFormatChange(durationHour):
    hours, mins = durationHour.split(":") # splits into hours and minutues by not including the ":"
    hours = int(hours) # converts into int
    minutes = int(mins) # converts into int
    totalMinutes = hours * 60 + minutes # converts hours into mins
    return totalMinutes

# Checks if a time string is in the valid "HH:MM" format
def isValidtimeFormatChange(timeInput):
    try:
        hours, minutes = timeInput.split(":") # splits into hours and minutues by not including the ":"
        hours = str(hours) # turns into str
        minutes = str(minutes) #turns into str 
        if len(hours) == 2 and len(minutes) == 2: # checks to see if the lens/digit has two numbers
            return True 
        return False
    except ValueError:
        return False

# this will dispaly the menu so that the user is able to input there choice 
def getAirlineChoice():
    print("Please choose one of the following options:")
    print("1 -- Find flight information by airline and flight number")
    print("2 -- Find flights shorter than a specified duration")
    print("3 -- Find the cheapest flight by a given airline")
    print("4 -- Find flight departing after a specified time")
    print("5 -- Find the average price of all flights")
    print("6 -- Write a file with flights sorted by departure time")
    print("7 -- Quit")

    choiceRange = True # set to truth so loop keeps running
    while choiceRange == True: # loop so user can use menu
        try:
            airlineChoice = int(input("Choice ==> ")) # this gets the user input 
            if 1 <= airlineChoice <= 7: # checks to see if num choice is in range
                return airlineChoice
            else:
                print("Entry must be between 1 and 7")
        except ValueError: # checks to see if anything other than a number is inputed
            print("Entry must be a number")
    return airlineChoice

# this finds the index of a specifc airline and flight number
def findSpecifcFlight(airlineSearch, flightSearch, airlineList, flightNumList):
    for i in range(len(airlineList)): # goes through a len loop
        if airlineList[i] == airlineSearch and flightNumList[i] == flightSearch: # if both users input match with the index
            return i # returns index if true 
    return -1 # returns -1 if none is found

# this will print the airlines name, num, time, etc
def printSpecificFlights(airlineList, flightNumList, departTimeList, arrivalTimeList, priceList):
    valid_airline = False # set it to false 
    while not valid_airline: 
        airlineSearch = input("Enter airline name: ") # user input 
        if airlineSearch not in airlineList: # handles if user airline search is not found
            print("Invalid input -- try again") # prints this if not found.
        else:
            valid_airline = True # if found sets upper loop to true.
            valid_flight = False 
            while not valid_flight:
                try:
                    flightSearch = int(input("Enter flight number: ")) # user input 
                    flightIndex = findSpecifcFlight(airlineSearch, flightSearch, airlineList, flightNumList) # calls the function to run it 
                    if flightIndex != -1: # if return != -1 then it will print the following text
                        print()
                        print("The flight that meets your criteria is: ")
                        print()
                        print("\nAIRLINE".ljust(8), "FLT#".ljust(6), "DEPART".rjust(7), "ARRIVE".rjust(7), "PRICE".rjust(3))
                        print(airlineList[flightIndex].ljust(8), str(flightNumList[flightIndex]).ljust(6),
                              departTimeList[flightIndex].rjust(7), arrivalTimeList[flightIndex].rjust(7), "$",
                              str(f"{priceList[flightIndex]:.0f}").rjust(3))
                        valid_flight = True # stops the loop if printed 
                        print()
                    else:
                        print("Flight not found. Please check the flight number and try again.")
                except ValueError:
                    print("Invalid input -- try again") # handles if anything other than number for flight num search is inputed

# Finds all flights shorter than a given duration
def findShortestFlight(departTimeList, arrivalTimeList, userShortestFlight):
    indexList = [] # index list
    for i in range(len(departTimeList)): # goes through the length of depart time list 
        depart = timeFormatChange(departTimeList[i]) # makes the time format of HH:MM into minutes 
        arrival = timeFormatChange(arrivalTimeList[i]) # makes the time format of HH:MM into minutes 
        duration = arrival - depart # subracts the minutes to find the shortest amount of minuties 
        if duration <= userShortestFlight: # if the duration is shorter than the users input it will be appended to list
            indexList.append(i)
    return indexList

# Prints flights that meet the maximum duration criteria
def ShortFlightPrint(airlineList, flightNumList, departTimeList, arrivalTimeList, priceList):
    shortFlight = False # loop is false 
    while not shortFlight: # while loop
        userShortestFlight = input("Enter maximum duration (in minutes): ") # as for user input 
        try:
            userShortestFlight = int(userShortestFlight) # sets it into a int 
            shortFlight = True # sets the loop to false 
        except ValueError: # handles if it cannot be turned into int
            print("Entry must be a number")

    shortIndex = findShortestFlight(departTimeList, arrivalTimeList, userShortestFlight) # calls back function
    if shortIndex != []: # if the list is not empty it prints out all the information
        print()
        print("The flights that meet your criteria are: ")
        print()
        print("\nAIRLINE".ljust(8), "FLT#".ljust(6), "DEPART".rjust(7), "ARRIVE".rjust(7), "PRICE".rjust(3))
        for index in shortIndex:
            print(airlineList[index].ljust(8), str(flightNumList[index]).ljust(6), departTimeList[index].rjust(7),
                  arrivalTimeList[index].rjust(7), "$", str(f"{priceList[index]:.0f}").rjust(3))
        print()
    else:
        print()
        print("No flights meet your criteria")
        print()


def cheapestAirline(priceList, userairlineSearch, airlineList):
    # sets the cheap price and find index to -1 so if nothng is found it'll return -1
    cheapPrice = 0
    findindex = -1
    # goes through all the airlines in the list
    for i in range(len(airlineList)):
        # check if the current airline matches the user-provided airline name
        if airlineList[i] == userairlineSearch:
            if cheapPrice == 0 or priceList[i] < cheapPrice: # the price is less than the cheap price 
                cheapPrice = priceList[i] # makes the cheap price equal to the price list 
                findindex = i # gets the index 
    return findindex #returns the index


# prints the search result of the cheap flight
def printCheapFlight(airlineList, flightNumList, departTimeList, arrivalTimeList, priceList):
    try:
        cheapFlight = False # set it to false 
        while not cheapFlight: # while loop
            userairlineSearch = input("Enter airline name: ") # user input 
            index = cheapestAirline(priceList, userairlineSearch, airlineList) # index is found by calling back function
            if index != -1: # if the index is not -1, prints out info
                print()
                print("The flight that meets your criteria is: ")
                print()
                print("\nAIRLINE".ljust(8), "FLT#".ljust(6), "DEPART".rjust(7), "ARRIVE".rjust(7), "PRICE".rjust(3))
                print(airlineList[index].ljust(8), str(flightNumList[index]).ljust(6), departTimeList[index].rjust(7),
                      arrivalTimeList[index].rjust(7), "$", str(f"{priceList[index]:.0f}").rjust(3))
                cheapFlight = True
                print()
            else:
                print("Invalid input -- try again")
    except ValueError: # handles any value errors
        print("Invalid input -- try again")

# this finds the depart time that is less of what the user has inputed 
def userDepartTime(departTimeList, userdepartInput):
    isValidtimeFormatChange(userdepartInput)  # checks if the input time format in correct (HH:MM)
    indexList = [] # empty index list 
    userdepartInput = timeFormatChange(userdepartInput)  # Convert the user departure time to total minutes
    for i in range(len(departTimeList)): # checks through the lengths of the depart time list
        departMinutes = timeFormatChange(departTimeList[i]) # sets all of them into mins
        if userdepartInput < departMinutes: # checks to see if depart mins is less than user input 
            indexList.append(i) # appends the index.
    if indexList: # returns index list or -1 
        return indexList
    return -1

# prints depart time 
def departTimePrint(airlineList, flightNumList, departTimeList, arrivalTimeList, priceList):
    departTime = False # sets loop to false
    userdepartInput = input("Enter earliest departure time: ") # users input 
    while not departTime: # while it is false 
        try:
            hours, minutes = userdepartInput.split(":") # spilits the hours and mins into seprate things
            hours = int(hours) # hours is set to int
            minutes = int(minutes) #min is set to int
            if 10 <= hours < 24 and 0 <= minutes < 60: # checks if user format is correct 
                departTime = True # stops loop
            else:
                userdepartInput = input("Invalid time - Try again ") # asks for user input 
        except ValueError:
            userdepartInput = input("Invalid time - Try again ") # ask for user input if there is a value error 

    DepartTimeIndex = userDepartTime(departTimeList, userdepartInput) # calls back function
    if DepartTimeIndex == -1: # if == -1 prints not found 
        print("\nNo flights meet your criteria\n")
    else: # prints the flights found
        print()
        print("The flights that meet your criteria are: ")
        print()
        print("AIRLINE".ljust(8), "FLT#".ljust(6), "DEPART".rjust(7), "ARRIVE".rjust(7), "PRICE".rjust(3))
        for index in DepartTimeIndex:
            print(
                airlineList[index].ljust(8),
                str(flightNumList[index]).ljust(6),
                departTimeList[index].rjust(7),
                arrivalTimeList[index].rjust(7),
                "$", str(f"{priceList[index]:.0f}").rjust(3)
            )
        print()

# finds the average price 
def averagePrice(priceList): 
    avePrice = 0 # set to 0
    for price in priceList: # goes through the prices in the list
        avePrice = avePrice + price # adds them 
    return avePrice / len(priceList) # avg is then found by divided total / length of list

# this will sort the depart list from earliest to latest
def selectionSort(departTimeList):
    rangeList = len(departTimeList) # checks for the length of list   
    index = list(range(rangeList)) # this will sort the list based on the depart time list
    for i in range(rangeList): # Outer loop to go through each element fof list
        minIndex = i # this sets the first index to the minIndex
        for j in range(i + 1, rangeList): # inner loop to check index but starting at the second index
            if timeFormatChange(departTimeList[index[j]]) < timeFormatChange(departTimeList[index[minIndex]]):
                minIndex = j # assume this is also one of the smallest index
        if minIndex != i: # If the smallest element is not already at position i, swap it with the current index
            temp = index[i] 
            index[i] = index[minIndex]
            index[minIndex] = temp
    return index


# this prints the information to a different file
def printOutfile(airlineList, flightNumList, departTimeList, arrivalTimeList, priceList):
    sortedIndex = selectionSort(departTimeList) # sorts the file index
    outfile = open("time-sorted-flights.csv", 'w') # opens a file to write 
    for i in sortedIndex: # for this sorted index this will print out the coressponding index 
        airline = airlineList[i] 
        flight = flightNumList[i]
        departTime = departTimeList[i]
        arrivalTime = arrivalTimeList[i]
        price = priceList[i]
        outfile.write(f"{airline},{flight},{departTime},{arrivalTime},${price:.0f}\n") # writes the file 
    outfile.close() # closes the file
    print()
    print("Sorted data has been written to file: time-sorted-flights.csv")
    print()

# this is where all the functions are called back from 1 - 7 and the choice that is selected will call back the function that is designated for that choice
def main():
    airlineList, flightNumList, departTimeList, arrivalTimeList, priceList = getData()
    Choice = True
    while Choice:
        airlineChoice = getAirlineChoice()
        if airlineChoice == 1:
            print()
            printSpecificFlights(airlineList, flightNumList, departTimeList, arrivalTimeList, priceList)
        elif airlineChoice == 2:
            print()
            ShortFlightPrint(airlineList, flightNumList, departTimeList, arrivalTimeList, priceList)
        elif airlineChoice == 3:
            print()
            printCheapFlight(airlineList, flightNumList, departTimeList, arrivalTimeList, priceList)
        elif airlineChoice == 4:
            print()
            departTimePrint(airlineList, flightNumList, departTimeList, arrivalTimeList, priceList)
        elif airlineChoice == 5:
            avg = averagePrice(priceList)
            print(f"The average price is ${avg:.2f}")
        elif airlineChoice == 6:
            printOutfile(airlineList, flightNumList, departTimeList, arrivalTimeList, priceList)
        elif airlineChoice == 7:
            print()
            print("Thank you for flying with us")
            Choice = False





