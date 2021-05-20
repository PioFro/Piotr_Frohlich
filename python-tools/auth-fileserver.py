import http.server
from http.server import SimpleHTTPRequestHandler
import sys
import base64

key = ""

class AuthHandler(SimpleHTTPRequestHandler):
    def do_HEAD(self):
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()

    def do_AUTHHEAD(self):
        self.send_response(401)
        self.send_header('WWW-Authenticate', 'Basic realm=\"Test\"')
        self.send_header('Content-type', 'text/html')
        self.end_headers()

    def do_GET(self):
        global key
        if self.headers.get('Authorization') == None:
            self.do_AUTHHEAD()
            self.wfile.write(str.encode('no auth header received'))
        elif str(self.headers.get('Authorization')) == 'Basic ' + key.decode():
            SimpleHTTPRequestHandler.do_GET(self)
        else:
            self.do_AUTHHEAD()
            self.wfile.write(str.encode(self.headers.get('Authorization')))
            self.wfile.write(str.encode('not authenticated'))



if __name__ == '__main__':
    if len(sys.argv) < 3:
        print("usage BasicAuthServer.py [port] [username:password]")
        sys.exit()
    key = base64.b64encode(str.encode(sys.argv[2]))
    s = http.server.HTTPServer(("0.0.0.0",int(sys.argv[1])),AuthHandler)
    s.serve_forever()