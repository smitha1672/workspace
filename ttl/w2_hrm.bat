SET PATH=C:\Program Files (x86)\teraterm;%PATH%
start TTERMPRO /C=18 /BAUD=115200 /M=%CD%\en_hrm_on_off.ttl
start TTERMPRO /C=19 /BAUD=115200 /M=%CD%\hrm_log.ttl
