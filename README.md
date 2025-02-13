### lib [t]orch [m]emory [a]lign align64 & round the cpu's allocation to full 8-byte memory blocks

```
cmake -DLOGGING=ON .. && make
LD_PRELOAD=./libtma.so python
>>> import torch
>>> torch.rand(1,3)
[tma-trace]: torch-alloc-cpu required=[12] return=[16] bytes ptr=0x5e1b1f28d2c0

```
