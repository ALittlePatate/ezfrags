import sys

"""
Basically converting a given pattern in this form :
8D 34 85 ? ? ? ? 89 15 ? ? ? ? 8B 41 08 8B 48 04 83 F9 FF
to this :
\x8D\x34\x85\x00\x00\x00\x00\x89\x15\x00\x00\x00\x00\x8B\x41\x08\x8B\x48\x04\x83\xF9\xFF
xxx????xx????xxxxxxxxx

It also generates the mask for the signature.
The code isn't optimized because idc
"""

sig = sys.argv[1]
sig = "\\x" + sig
temp = sig.replace(" ","\\x")
res = temp.replace("?","00")
print(res)

res_list = sig.split(" ")
res_mask = ""
for charac in res_list :
    if charac == "?" :
        res_mask += "?"
    else :
        res_mask += "x"

print(res_mask)