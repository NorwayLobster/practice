SRC_DIR=.
DST_DIR=.
IMPORT_PATH=.
protoc -I$(IMPORT_PATH) --cpp_out=$(DST_DIR) $(SRC_DIR)/wc.SearchRequest.proto   
#protoc --proto_path=$(IMPORT_PATH) 
