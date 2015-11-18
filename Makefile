.PHONY: registers

registers:
	$(MAKE) -C src

clean:
	rm -f *.o *.gch
	$(MAKE) -C src

