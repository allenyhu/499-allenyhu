#include "chirp.grpc.pb.h"

class KeyValueStoreServiceImpl final : public Chirp::Service {

};

void RunServer() {
  std::string server_address("0.0.0.0:5000");
  KeyValueStoreServiceImpl service;

  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsercureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "KeyValue Server listening on " << server_address << std::endl;

  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();
  return 0;
}
