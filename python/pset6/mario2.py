height = int(input("Height:"))
empty_space = height - 1
block = "#"


while len(block) <= height:
    print(f"{' ' * empty_space}{block} {block}")
    empty_space = empty_space -1
    block = block + "#"
