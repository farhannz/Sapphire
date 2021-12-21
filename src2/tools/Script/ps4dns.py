import socket
from urllib2 import urlopen

class DNSQuery:
  def __init__(self, data):
    self.data=data
    self.domain=''

    qtype = (ord(data[2]) >> 3) & 15   # Opcode bits
    if qtype == 0:                     # Standard query
      index=12
      lon=ord(data[index])
      while lon != 0:
        self.domain+=data[index+1:index+lon+1]+'.'
        index+=lon+1
        lon=ord(data[index])

  def request(self, ip):
    packet=''
    if self.domain:
      packet+=self.data[:2] + "\x81\x80"
      packet+=self.data[4:6] + self.data[4:6] + '\x00\x00\x00\x00'   # Questions and Answers Counts
      packet+=self.data[12:]                                         # Original Domain Name Question
      packet+='\xc0\x0c'                                             # Pointer to domain name
      packet+='\x00\x01\x00\x01\x00\x00\x00\x3c\x00\x04'             # Response type, ttl and resource data length -> 4 bytes
      packet+=str.join('',map(lambda x: chr(int(x)), ip.split('.'))) # 4bytes of IP
    return packet

if __name__ == '__main__':
  #ip=socket.gethostbyname(socket.gethostname())
  #ip = urlopen('http://ip.42.pl/raw').read()
  ip = "212.43.86.40"
  print 'DNS server started on %s intercepting to %s' % (socket.gethostbyname(socket.gethostname()), ip)

  udps = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
  udps.bind(('',53))
  
  try:
    while 1:
      data, addr = udps.recvfrom(1024)
      p=DNSQuery(data)
      if "neolobby" in p.domain:
        udps.sendto(p.request(ip), addr) #send answer
        print 'Intercepted request: %s -> %s' % (p.domain, ip)
      else:
        try:
          r_ip = socket.gethostbyname(p.domain)
        except:
          r_ip = ip
        udps.sendto(p.request(r_ip), addr) #send answer
        print 'Normal request: %s -> %s' % (p.domain, r_ip)
  except KeyboardInterrupt:
    udps.close()