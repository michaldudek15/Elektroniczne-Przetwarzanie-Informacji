import string

# english message example with shift 3:
# QEB NRFZH YOLTK CLU GRJMP LSBO QEB IXWV ALD

# polish message example with shift -3:
# OHBÓŻ DĆFĄ, EKTRP ŚZŃM YŹSŁ L UAGWĘ INCJ


def shift(text, move, alphabet):
    move %= len(alphabet)
    shifted_alphabet = alphabet[move:] + alphabet[:move]
    table = str.maketrans(alphabet, shifted_alphabet)
    shifted = text.translate(table)
    print("shifted message: " + '\033[94m' + shifted + '\033[0m')


while True:
    option = input('choose your alphabet, type 1 for latin or 2 for polish: ')
    if len(option) == 1 and (option == "1" or option == "2"):
        break
    else:
        print('\033[93m' + 'please type either 1 or 2 to continue\n' + '\033[0m')
        continue

print("now type the message you want to cipher:")
message = input().lower()
shift_value = int(input("choose shift value: "))

if option == "1":
    shift(message, shift_value, string.ascii_lowercase)
elif option == "2":
    shift(message, shift_value, "aąbcćdeęfghijklłmnńoóprsśtuwyzźż")
else:
    print("something went wrong :((")
