.PHONY: %_make_debug
%_make_debug:
	cd ./$* && make -f $*.mk debug

.PHONY: %_outd
%_outd:	
	cd ./$*/build && ./$*_debug

.PHONY: %_rc
%_rc:	
	cd ./$*/build && ./$*_rc

.PHONY: %_clean
%_clean:	
	cd ./$* && make -f $*.mk clean

.PHONY: %_vlgd
%_vlgd:	
	cd ./$* && valgrind --leak-check=yes --track-origins=yes ../$*/build/$*_debug

.PHONY: %_cgdbd
%_cgdbd:	
	cd ./$* && cgdb ./build/$*_debug

