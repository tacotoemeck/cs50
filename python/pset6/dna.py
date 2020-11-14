from sys import argv
from csv import reader, DictReader
from textwrap import wrap

if len(argv) != 3:
    print('Usage: python dna.py data.csv sequence.txt')
    exit()

# read the dna sequence from the file

with open(argv[2]) as sequence_file:
    dnareader = reader(sequence_file)
    for row in dnareader:
        sequence = row[0]

# count repeated STRs

database_array = []

dna_file = open(argv[1], "r")
dict_reader = DictReader(dna_file)
for row in dict_reader:
    dict_from_csv = dict(row)
    database_array.append(dict_from_csv)
# print(database_array)
# get list of strts to search for
strs = []

for key in database_array[0]:
    if key != 'name':
        strs.append(key)

# count longest repating sequence of each str in the dna sequence

sequencesCount = {}

for val in strs:
    str_length = len(val)
    last_str = ""
    current_seq_len = 0
    max_seq_len = 0
    # find first occurance of the str
    strIndex = sequence.find(val)
    # split the string from the index of first str every str_length char
    STRSplit = wrap(sequence[strIndex:], str_length)
    for seq in STRSplit:
        if seq == last_str and last_str == val:
            current_seq_len += 1
        if current_seq_len > max_seq_len:
            max_seq_len = current_seq_len
        else:
            current_seq_len = 1
            last_str = seq

    sequencesCount[val] = str(max_seq_len)

print(sequencesCount)

for entry in database_array:
    print(entry)
    duplicates = entry.items() & sequencesCount.items()
    if(len(duplicates)  == len(sequencesCount)):
        print(entry['name'])
        match = entry['name']



