# I Like To Eduroam Around

The Latour branch is likely to be pulled into cabinets on campuses where actors need following, so a handy guide to keeping a Pi on an Eduroam network is a must!

### Disable network service

`sudo service networking stop`

### Write a wpa_supplicant configuration file with your username and password.

```

network={
    # --- MUST CONFIGURE THE FOLLOWING THREE OPTIONS --
    # Refer to your university's guide to eduroam to amend this to suit
    # The 'identity' is the username actually used for authentication.
    # This must be your University IT username, all lowercase.
    identity="my_username1234"
    # Your normal University IT password (so make sure the permissions on
    # your wpa_supplicant config file are not world readable!)
    # so change permissions with `sudo chmod 600`
    password="my_University_password"
    # Get your advised CA cert from the university if it is not already
    # in `/etc/ssl/certs`
    # Change the path to where you keep the file, usually
    ca_cert="/etc/ssl/certs/my_recommended_pem_cert_file.pem"
    # --- ONLY CHANGE BELOW IF YOU ARE NOT A MEMBER --
    # --- OF THE UNIVERSITY OF BRISTOL, UK          --
    # Your University IT may support PEAP and TTLS. Remove accordingly
    eap=PEAP TTLS
    # The 'anonymous_identity' is the identity used for routing
    # the authentication to your University. It must end with '@my_university.ac.uk'
    # or '@my_university.ac.uk'. It must be all lowercase. If you have 
    # anything preceding the @ it must be all lowercase letters or 
    # a hyphen (no spaces, punctuation etc) 
    # e.g. "wireless-user@my-universtiy.ac.uk" would be ok
    anonymous_identity="@my_university.ac.uk"
    # your University likely to use MS-CHAPv2 as the inner authentication scheme,
    # with the traditional label
    phase1="peaplabel=0"
    phase2="auth=MSCHAPV2"
    # Set priority to a big number
    priority=999
    # --- DONT CHANGE THE REST OF THIS BLOCK --
    # Enable this network block
    disabled=0
    # eduroam please
    ssid="eduroam"
    # SSID should be broadcast, so don't scan.
    scan_ssid=0
    # Infrastructure mode
    mode=0
    # WPA/WPA2 require OPEN
    auth_alg=OPEN
    # WPA and WPA2 (RSN) are both used for eduroam
    # (depending on which organisation you are at)
    # In the future 'WPA' can be removed (WPA2 only).
    proto=WPA RSN
    # CCMP (AES) is stronger, but some organisations use TKIP
    # In the future 'TKIP' can be removed
    pairwise=CCMP TKIP
    # Use EAP
    key_mgmt=WPA-EAP
    # Use PMKSA caching
    proactive_key_caching=1
}

```


### Connect to the wireless network using wpa_supplicant

`sudo wpa_supplicant -i wlan0 -c /path/to/wpa_supplicant.conf -B`

### Make this happen on boot with `cron`

`sudo crontab -e` choose nano or vim depending on preference if its the first time you making a cron file, otherwise add this rule to your crontab file

```
@reboot service networking stop && wpa_supplicant -i wlan0 -c /path/to/wpa_supplicant.conf -B
```
Note you don't need to use sudo in cron, cron is running for the pi user with its priveleges.

Also you seperate the two commands with `;` to denote run regardless of outcome of the previous command. If you want them to run only if the previous one exits successfully, (good idea) use `&&`. If you want commands to run in parrallel then make seperate cron commands with a new line 

### Request an IP address with dhclient.

This didn't work for me, but maybe it's specific to my university
Verify it's working with `iwconfig` then request an ip address with
`sudo dhclient wlan0` 

and check if wlan0 was been given an address using `ifconfig`

I think mine was just auto-assigned
