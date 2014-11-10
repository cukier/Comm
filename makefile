CC=Ccsc.exe
pk2=pk2cmd

DEVICE=PIC18F252
PROJ_FILE=master
PROJ=Master
PROJ_FILE2=slave
PROJ2=Slave

CFLAGS=+FH +LN -T -A -M -Z +DF +Y=9 +STDOUT +EA
HFLAGS=+FB +LN -T -A -M -Z +DF +Y=9 +STDOUT +EA
PK2FLAGS=-X -E -P $(DEVICE) -M -F $(PROJ_FILE).hex

all: $(PROJ) $(PROJ2)

$(PROJ): $(PROJ_FILE).c
	$(CC) $(CFLAGS) $(PROJ_FILE).c
	
$(PROJ2): $(PROJ_FILE2).c
	$(CC) $(CFLAGS) $(PROJ_FILE2).c

Burn:
	$(pk2) $(PK2FLAGS)

clean:
	rm *.cof *.err *.esym *.hex *.lst