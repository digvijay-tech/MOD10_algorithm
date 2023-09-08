# LUHN ALGORITHM

----

The Luhn algorithm, also known as the "modulus 10" or "mod 10" algorithm, is a simple checksum formula used to validate a variety of identification numbers, such as credit card numbers, IMEI numbers (for mobile phones), and more. It helps detect accidental errors in the data and is commonly used to check whether a given number is potentially valid before processing it further.


__Algorithm Steps:__

__1. Starting from the rightmost digit (the least significant digit) and moving left, double the value of every second digit. If doubling a digit results in a value greater than 9, subtract 9 from the result.__

For example, if you have the number `4532015118129745`, the doubled digits are:
````
4 5 3 2 0 1 5 1 1 8 1 2 9 7 4 5
8   4   2   1   1   1   2   7   1   5
````

__2. Sum all the digits in the number, including the ones you didn't double.__
````
8 + 4 + 5 + 3 + 2 + 1 + 1 + 1 + 2 + 7 + 1 + 5 = 40
````

__3. If the total sum is divisible by 10 (i.e., the remainder when divided by 10 is 0), then the number is potentially valid according to the Luhn algorithm.__
In this example, `40 % 10 = 0`, so the number `4532015118129745` passes the Luhn test.

__Purpose of the Luhn Algorithm:__

The Luhn algorithm is primarily used to catch errors in data entry or transmission. For example, when a credit card number is entered on a website or point-of-sale terminal, the system can quickly check whether the number is potentially valid using the Luhn test before sending it for authorization. This helps prevent common mistakes, such as mistyped digits, and reduces the number of invalid transactions sent to payment processors.

__Note__: Passing the Luhn test does not guarantee that a number is valid or active; it merely checks the number's format for accuracy. Actual authorization and validation of credit card numbers involve additional checks with financial institutions.

In summary, the Luhn algorithm is a straightforward checksum formula used to validate various identification numbers by verifying their format. It is a quick and effective way to catch common data entry errors but does not verify the authenticity or validity of the number in a broader sense.



__Dummy Test Cards:__
````
Will Pass:
-> 4525908427216116
-> 5555555555554444
-> 4444333322221111
````
````
Will Not Pass:
-> 4525908427216114
-> 5525908427216116
-> 4444333322221116
````
