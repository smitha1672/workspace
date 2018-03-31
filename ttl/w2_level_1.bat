SET PATH=C:\Program Files (x86)\teraterm;%PATH%
::PCBA CLI
start TTERMPRO /C=19 /BAUD=115200 /M=%CD%\pcba_log.ttl

:: for pervious setting
::start TTERMPRO /C=8 /BAUD=115200 /M=%CD%\en_syslog.ttl
::start TTERMPRO /C=11 /BAUD=115200 /M=%CD%\gnss_test.ttl
::start TTERMPRO /C=9 /BAUD=115200 /M=%CD%\level_1.ttl
