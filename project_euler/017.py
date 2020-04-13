tab1 = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
tab2 = ["", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]

def English(num):
    if num < 20:
        return tab1[num]
    elif 20 <= num < 100:
        return tab2[num // 10] + (tab1[num % 10] if num % 10 != 0 else "")
    elif 100 <= num < 1000:
        return tab1[num // 100] + "hundred" + (("and" + English(num % 100)) if num % 100 != 0 else "")
    elif 1000 <= num < 1000000:
        return English(num // 1000) + "thousand" + (English(num % 1000) if num % 1000 != 0 else "")

print(sum(len(English(num)) for num in range(1, 1001)))