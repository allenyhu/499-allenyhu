#include "chirp.grpc.pb.h"

class KeyValueStoreServiceImpl final : public Chirp::Service {
  Status put(ServerContext* context, PutRequest* request) override {
    bool status = store.put(request->key, request->value);
    if (status) {
      return Status::OK;
    }
    return Status::CANCELLED; // should error handling be handled in grpc or actual implementation?
  }

  Status get(ServerContext* context, 
	     ServerReaderWriter(GetRequest, GetReply>* stream) override {
    std::vector<GetRequest> received_requests;
    GetRequest req;
    while (stream->Read(&req)) {
      for (const GetRequest r : received_requests) {
        
      }
    }

    return Status::OK;
  }
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
