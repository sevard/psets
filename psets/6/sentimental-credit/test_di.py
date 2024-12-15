card_info = {
        'AMEX': {
            'first_two': ['34', '37'],
            'cc_len': [15, ],
            },
        'MASTERCARD': {
            'first_two': ['51', '52', '53', '54', '55'],
            'cc_len': [16, ],
        },
        'VISA': {
            'first_two': ['40', '41', '42', '43', '44', '45', '46', '47', '48', '49'],
            'cc_len': [13, 16],
        },
    }

for k, v in card_info.items():
    print(k, v)
