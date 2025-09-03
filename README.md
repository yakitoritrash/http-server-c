# http-server-c

A simple, lightweight HTTP server written in C. This project demonstrates basic networking concepts, HTTP protocol handling, and provides a minimal web server suitable for learning, experimentation, or embedding in small projects.

## Features

- Serves static files over HTTP/1.0 and/or HTTP/1.1
- Minimal dependencies (standard C libraries and sockets)
- Simple configuration and usage
- Supports basic HTTP methods (GET, HEAD)
- Handles multiple connections (single-threaded or select-based)
- Easily extensible for more features

## Getting Started

### Prerequisites

- A C compiler (e.g., gcc, clang)
- Unix-like OS (Linux, macOS) or Windows with Winsock support

### Building

Clone the repository:

```sh
git clone https://github.com/yakitoritrash/http-server-c.git
cd http-server-c
```

Compile:

```sh
gcc -o tcpechoserver tcpechoserver.c
```

You may need to adjust the above command if you have multiple source files or need additional flags (e.g., `-lpthread`).

### Running

```sh
./http-server [PORT] [DOCUMENT_ROOT]
```

- `PORT`: (Optional) Port number to listen on (default: 8080)
- `DOCUMENT_ROOT`: (Optional) Directory to serve files from (default: current directory)

Example:

```sh
./http-server 8080 /var/www/html
```

Then visit `http://localhost:8080` in your web browser.

## Project Structure

- `tcpechoserver.c` — main server file

## Usage

- Place static files (HTML, CSS, JS, images) in the document root directory.
- Supported HTTP methods: `GET` and `HEAD`.

## Limitations

- No HTTPS support (for learning/demo purposes only)
- Basic HTTP protocol handling (no CGI, no POST/PUT)
- No directory listing by default
- Not intended for production use

## Contributing

Pull requests and issues are welcome! Please open an issue to discuss any major changes before submitting PRs.

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.

---

*Educational project by [yakitoritrash](https://github.com/yakitoritrash).*
