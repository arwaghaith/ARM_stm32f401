import argparse

def generate_masks(bit_idx, bit_length, start_idx, prefix):
    masks = []
    for i in range(bit_length):
        mask = 1 << (bit_idx + i)
        masks.append(f"#define {prefix}_MASK{i+start_idx} 0x{mask:02X}")
    return masks

def write_to_file(filename, masks):
    with open(filename, 'w') as file:
        for mask in masks:
            file.write(mask + '\n')

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-bit_idx', type=int, help='Bit index')
    parser.add_argument('-bit_length', type=int, help='Bit length')
    parser.add_argument('-start_idx', type=int, help='Start index')
    parser.add_argument('-prefix', type=str, help='Prefix')
    args = parser.parse_args()

    masks = generate_masks(args.bit_idx, args.bit_length, args.start_idx, args.prefix)
    write_to_file('output.c', masks)