.PHONY: %_debug
%_debug:
	cd ./$* && make -f $*.mk debug

.PHONY: %_rc
%_rc:
	cd ./$* && make -f $*.mk release

.PHONY: %_run_debug
%_run_debug:	
	cd ./$*/build && ./$*_debug

.PHONY: %_run_rc
%_run_rc:	
	cd ./$*/build && ./$*_rc

.PHONY: %_clean
%_clean:	
	cd ./$* && make -f $*.mk clean

