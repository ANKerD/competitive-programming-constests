# coding: utf-8
rules = [
    lambda s: any(x.islower() for x in s),
    lambda s: any(x.isupper() for x in s),
    lambda s: any(x.isdigit() for x in s),
    lambda s: all(x not in '!@#$%*() .,´`-_=+[]\{\}~^' for x in s),
    lambda s: len(s) >= 6,
    lambda s: len(s) <= 32,
]
while True:
    try:
        s = raw_input()
        if all(rule(s) for rule in rules):
            print 'Senha valida.'
        else:
            print 'Senha invalida.'
    except Exception as e:
        break