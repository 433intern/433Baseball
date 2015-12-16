#include "stdafx.h"

namespace protocol {

namespace {

const ::google::protobuf::Descriptor* PacketHeader_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  PacketHeader_reflection_ = NULL;
const ::google::protobuf::Descriptor* RoomInfo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  RoomInfo_reflection_ = NULL;
const ::google::protobuf::Descriptor* CS_contact_alram_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CS_contact_alram_reflection_ = NULL;
const ::google::protobuf::Descriptor* CS_room_info_request_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CS_room_info_request_reflection_ = NULL;
const ::google::protobuf::Descriptor* CS_total_room_info_request_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CS_total_room_info_request_reflection_ = NULL;
const ::google::protobuf::Descriptor* CS_room_create_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CS_room_create_reflection_ = NULL;
const ::google::protobuf::Descriptor* CS_room_join_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CS_room_join_reflection_ = NULL;
const ::google::protobuf::Descriptor* CS_room_leave_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CS_room_leave_reflection_ = NULL;
const ::google::protobuf::Descriptor* CS_request_ingame_start_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CS_request_ingame_start_reflection_ = NULL;
const ::google::protobuf::Descriptor* SC_contact_result_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SC_contact_result_reflection_ = NULL;
const ::google::protobuf::Descriptor* SC_room_info_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SC_room_info_reflection_ = NULL;
const ::google::protobuf::Descriptor* SC_total_room_info_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SC_total_room_info_reflection_ = NULL;
const ::google::protobuf::Descriptor* SC_room_create_result_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SC_room_create_result_reflection_ = NULL;
const ::google::protobuf::Descriptor* SC_room_join_result_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SC_room_join_result_reflection_ = NULL;
const ::google::protobuf::Descriptor* SC_room_leave_result_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SC_room_leave_result_reflection_ = NULL;
const ::google::protobuf::Descriptor* SC_ingame_start_result_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SC_ingame_start_result_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* PacketType_descriptor_ = NULL;
const ::google::protobuf::EnumDescriptor* FailSignal_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_RoomPacket_2eProto() {
  protobuf_AddDesc_RoomPacket_2eProto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "RoomPacket.Proto");
  GOOGLE_CHECK(file != NULL);
  PacketHeader_descriptor_ = file->message_type(0);
  static const int PacketHeader_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PacketHeader, size_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PacketHeader, type_),
  };
  PacketHeader_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      PacketHeader_descriptor_,
      PacketHeader::default_instance_,
      PacketHeader_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PacketHeader, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(PacketHeader, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(PacketHeader));
  RoomInfo_descriptor_ = file->message_type(1);
  static const int RoomInfo_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RoomInfo, roomnum_),
  };
  RoomInfo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      RoomInfo_descriptor_,
      RoomInfo::default_instance_,
      RoomInfo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RoomInfo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(RoomInfo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(RoomInfo));
  CS_contact_alram_descriptor_ = file->message_type(2);
  static const int CS_contact_alram_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CS_contact_alram, nickname_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CS_contact_alram, securitycode_),
  };
  CS_contact_alram_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CS_contact_alram_descriptor_,
      CS_contact_alram::default_instance_,
      CS_contact_alram_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CS_contact_alram, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CS_contact_alram, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CS_contact_alram));
  CS_room_info_request_descriptor_ = file->message_type(3);
  static const int CS_room_info_request_offsets_[1] = {
  };
  CS_room_info_request_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CS_room_info_request_descriptor_,
      CS_room_info_request::default_instance_,
      CS_room_info_request_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CS_room_info_request, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CS_room_info_request, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CS_room_info_request));
  CS_total_room_info_request_descriptor_ = file->message_type(4);
  static const int CS_total_room_info_request_offsets_[1] = {
  };
  CS_total_room_info_request_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CS_total_room_info_request_descriptor_,
      CS_total_room_info_request::default_instance_,
      CS_total_room_info_request_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CS_total_room_info_request, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CS_total_room_info_request, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CS_total_room_info_request));
  CS_room_create_descriptor_ = file->message_type(5);
  static const int CS_room_create_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CS_room_create, roomnum_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CS_room_create, id_),
  };
  CS_room_create_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CS_room_create_descriptor_,
      CS_room_create::default_instance_,
      CS_room_create_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CS_room_create, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CS_room_create, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CS_room_create));
  CS_room_join_descriptor_ = file->message_type(6);
  static const int CS_room_join_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CS_room_join, roomnum_),
  };
  CS_room_join_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CS_room_join_descriptor_,
      CS_room_join::default_instance_,
      CS_room_join_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CS_room_join, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CS_room_join, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CS_room_join));
  CS_room_leave_descriptor_ = file->message_type(7);
  static const int CS_room_leave_offsets_[1] = {
  };
  CS_room_leave_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CS_room_leave_descriptor_,
      CS_room_leave::default_instance_,
      CS_room_leave_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CS_room_leave, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CS_room_leave, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CS_room_leave));
  CS_request_ingame_start_descriptor_ = file->message_type(8);
  static const int CS_request_ingame_start_offsets_[1] = {
  };
  CS_request_ingame_start_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CS_request_ingame_start_descriptor_,
      CS_request_ingame_start::default_instance_,
      CS_request_ingame_start_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CS_request_ingame_start, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CS_request_ingame_start, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CS_request_ingame_start));
  SC_contact_result_descriptor_ = file->message_type(9);
  static const int SC_contact_result_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SC_contact_result, failsignal_),
  };
  SC_contact_result_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SC_contact_result_descriptor_,
      SC_contact_result::default_instance_,
      SC_contact_result_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SC_contact_result, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SC_contact_result, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SC_contact_result));
  SC_room_info_descriptor_ = file->message_type(10);
  static const int SC_room_info_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SC_room_info, playernicknames_),
  };
  SC_room_info_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SC_room_info_descriptor_,
      SC_room_info::default_instance_,
      SC_room_info_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SC_room_info, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SC_room_info, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SC_room_info));
  SC_total_room_info_descriptor_ = file->message_type(11);
  static const int SC_total_room_info_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SC_total_room_info, roomcount_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SC_total_room_info, roomlist_),
  };
  SC_total_room_info_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SC_total_room_info_descriptor_,
      SC_total_room_info::default_instance_,
      SC_total_room_info_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SC_total_room_info, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SC_total_room_info, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SC_total_room_info));
  SC_room_create_result_descriptor_ = file->message_type(12);
  static const int SC_room_create_result_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SC_room_create_result, failsignal_),
  };
  SC_room_create_result_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SC_room_create_result_descriptor_,
      SC_room_create_result::default_instance_,
      SC_room_create_result_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SC_room_create_result, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SC_room_create_result, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SC_room_create_result));
  SC_room_join_result_descriptor_ = file->message_type(13);
  static const int SC_room_join_result_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SC_room_join_result, failsignal_),
  };
  SC_room_join_result_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SC_room_join_result_descriptor_,
      SC_room_join_result::default_instance_,
      SC_room_join_result_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SC_room_join_result, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SC_room_join_result, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SC_room_join_result));
  SC_room_leave_result_descriptor_ = file->message_type(14);
  static const int SC_room_leave_result_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SC_room_leave_result, failsignal_),
  };
  SC_room_leave_result_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SC_room_leave_result_descriptor_,
      SC_room_leave_result::default_instance_,
      SC_room_leave_result_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SC_room_leave_result, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SC_room_leave_result, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SC_room_leave_result));
  SC_ingame_start_result_descriptor_ = file->message_type(15);
  static const int SC_ingame_start_result_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SC_ingame_start_result, failsignal_),
  };
  SC_ingame_start_result_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SC_ingame_start_result_descriptor_,
      SC_ingame_start_result::default_instance_,
      SC_ingame_start_result_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SC_ingame_start_result, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SC_ingame_start_result, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SC_ingame_start_result));
  PacketType_descriptor_ = file->enum_type(0);
  FailSignal_descriptor_ = file->enum_type(1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_RoomPacket_2eProto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    PacketHeader_descriptor_, &PacketHeader::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    RoomInfo_descriptor_, &RoomInfo::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CS_contact_alram_descriptor_, &CS_contact_alram::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CS_room_info_request_descriptor_, &CS_room_info_request::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CS_total_room_info_request_descriptor_, &CS_total_room_info_request::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CS_room_create_descriptor_, &CS_room_create::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CS_room_join_descriptor_, &CS_room_join::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CS_room_leave_descriptor_, &CS_room_leave::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CS_request_ingame_start_descriptor_, &CS_request_ingame_start::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SC_contact_result_descriptor_, &SC_contact_result::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SC_room_info_descriptor_, &SC_room_info::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SC_total_room_info_descriptor_, &SC_total_room_info::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SC_room_create_result_descriptor_, &SC_room_create_result::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SC_room_join_result_descriptor_, &SC_room_join_result::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SC_room_leave_result_descriptor_, &SC_room_leave_result::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SC_ingame_start_result_descriptor_, &SC_ingame_start_result::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_RoomPacket_2eProto() {
  delete PacketHeader::default_instance_;
  delete PacketHeader_reflection_;
  delete RoomInfo::default_instance_;
  delete RoomInfo_reflection_;
  delete CS_contact_alram::default_instance_;
  delete CS_contact_alram_reflection_;
  delete CS_room_info_request::default_instance_;
  delete CS_room_info_request_reflection_;
  delete CS_total_room_info_request::default_instance_;
  delete CS_total_room_info_request_reflection_;
  delete CS_room_create::default_instance_;
  delete CS_room_create_reflection_;
  delete CS_room_join::default_instance_;
  delete CS_room_join_reflection_;
  delete CS_room_leave::default_instance_;
  delete CS_room_leave_reflection_;
  delete CS_request_ingame_start::default_instance_;
  delete CS_request_ingame_start_reflection_;
  delete SC_contact_result::default_instance_;
  delete SC_contact_result_reflection_;
  delete SC_room_info::default_instance_;
  delete SC_room_info_reflection_;
  delete SC_total_room_info::default_instance_;
  delete SC_total_room_info_reflection_;
  delete SC_room_create_result::default_instance_;
  delete SC_room_create_result_reflection_;
  delete SC_room_join_result::default_instance_;
  delete SC_room_join_result_reflection_;
  delete SC_room_leave_result::default_instance_;
  delete SC_room_leave_result_reflection_;
  delete SC_ingame_start_result::default_instance_;
  delete SC_ingame_start_result_reflection_;
}

void protobuf_AddDesc_RoomPacket_2eProto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\020RoomPacket.Proto\022\010protocol\"*\n\014PacketHe"
    "ader\022\014\n\004size\030\001 \001(\007\022\014\n\004type\030\002 \001(\007\"\033\n\010Room"
    "Info\022\017\n\007roomNum\030\001 \001(\r\":\n\020CS_contact_alra"
    "m\022\020\n\010nickName\030\001 \002(\t\022\024\n\014securityCode\030\002 \001("
    "\t\"\026\n\024CS_room_info_request\"\034\n\032CS_total_ro"
    "om_info_request\"-\n\016CS_room_create\022\017\n\007roo"
    "mNum\030\001 \001(\r\022\n\n\002id\030\002 \001(\t\"\037\n\014CS_room_join\022\017"
    "\n\007roomNum\030\001 \001(\r\"\017\n\rCS_room_leave\"\031\n\027CS_r"
    "equest_ingame_start\"=\n\021SC_contact_result"
    "\022(\n\nfailSignal\030\001 \001(\0162\024.protocol.FailSign"
    "al\"\'\n\014SC_room_info\022\027\n\017playerNickNames\030\001 "
    "\003(\t\"M\n\022SC_total_room_info\022\021\n\troomCount\030\001"
    " \001(\r\022$\n\010roomList\030\002 \003(\0132\022.protocol.RoomIn"
    "fo\"A\n\025SC_room_create_result\022(\n\nfailSigna"
    "l\030\001 \001(\0162\024.protocol.FailSignal\"\?\n\023SC_room"
    "_join_result\022(\n\nfailSignal\030\001 \001(\0162\024.proto"
    "col.FailSignal\"@\n\024SC_room_leave_result\022("
    "\n\nfailSignal\030\001 \001(\0162\024.protocol.FailSignal"
    "\"B\n\026SC_ingame_start_result\022(\n\nfailSignal"
    "\030\001 \001(\0162\024.protocol.FailSignal*\352\002\n\nPacketT"
    "ype\022\013\n\007UNKNOWN\020\000\022\024\n\020CS_CONTACT_ALRAM\020\001\022\022"
    "\n\016CS_ROOM_CREATE\020\002\022\020\n\014CS_ROOM_JOIN\020\003\022\025\n\021"
    "SC_CONTACT_RESULT\020\004\022\031\n\025SC_ROOM_CREATE_RE"
    "SULT\020\005\022\027\n\023SC_ROOM_JOIN_RESULT\020\006\022\021\n\rCS_RO"
    "OM_LEAVE\020\007\022\033\n\027CS_REQUEST_INGAME_START\020\010\022"
    "\030\n\024CS_ROOM_INFO_REQUEST\020\t\022\036\n\032CS_TOTAL_RO"
    "OM_INFO_REQUEST\020\n\022\030\n\024SC_ROOM_LEAVE_RESUL"
    "T\020\013\022\032\n\026SC_INGAME_START_RESULT\020\014\022\020\n\014SC_RO"
    "OM_INFO\020\r\022\026\n\022SC_TOTAL_ROOM_INFO\020\016*S\n\nFai"
    "lSignal\022\013\n\007SUCCESS\020\000\022\014\n\010NO_EXIST\020\001\022\r\n\tFU"
    "LL_ROOM\020\002\022\033\n\027EXIST_REPETITION_NUMBER\020\003", 1238);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "RoomPacket.Proto", &protobuf_RegisterTypes);
  PacketHeader::default_instance_ = new PacketHeader();
  RoomInfo::default_instance_ = new RoomInfo();
  CS_contact_alram::default_instance_ = new CS_contact_alram();
  CS_room_info_request::default_instance_ = new CS_room_info_request();
  CS_total_room_info_request::default_instance_ = new CS_total_room_info_request();
  CS_room_create::default_instance_ = new CS_room_create();
  CS_room_join::default_instance_ = new CS_room_join();
  CS_room_leave::default_instance_ = new CS_room_leave();
  CS_request_ingame_start::default_instance_ = new CS_request_ingame_start();
  SC_contact_result::default_instance_ = new SC_contact_result();
  SC_room_info::default_instance_ = new SC_room_info();
  SC_total_room_info::default_instance_ = new SC_total_room_info();
  SC_room_create_result::default_instance_ = new SC_room_create_result();
  SC_room_join_result::default_instance_ = new SC_room_join_result();
  SC_room_leave_result::default_instance_ = new SC_room_leave_result();
  SC_ingame_start_result::default_instance_ = new SC_ingame_start_result();
  PacketHeader::default_instance_->InitAsDefaultInstance();
  RoomInfo::default_instance_->InitAsDefaultInstance();
  CS_contact_alram::default_instance_->InitAsDefaultInstance();
  CS_room_info_request::default_instance_->InitAsDefaultInstance();
  CS_total_room_info_request::default_instance_->InitAsDefaultInstance();
  CS_room_create::default_instance_->InitAsDefaultInstance();
  CS_room_join::default_instance_->InitAsDefaultInstance();
  CS_room_leave::default_instance_->InitAsDefaultInstance();
  CS_request_ingame_start::default_instance_->InitAsDefaultInstance();
  SC_contact_result::default_instance_->InitAsDefaultInstance();
  SC_room_info::default_instance_->InitAsDefaultInstance();
  SC_total_room_info::default_instance_->InitAsDefaultInstance();
  SC_room_create_result::default_instance_->InitAsDefaultInstance();
  SC_room_join_result::default_instance_->InitAsDefaultInstance();
  SC_room_leave_result::default_instance_->InitAsDefaultInstance();
  SC_ingame_start_result::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_RoomPacket_2eProto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_RoomPacket_2eProto {
  StaticDescriptorInitializer_RoomPacket_2eProto() {
    protobuf_AddDesc_RoomPacket_2eProto();
  }
} static_descriptor_initializer_RoomPacket_2eProto_;
const ::google::protobuf::EnumDescriptor* PacketType_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return PacketType_descriptor_;
}
bool PacketType_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
      return true;
    default:
      return false;
  }
}

const ::google::protobuf::EnumDescriptor* FailSignal_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return FailSignal_descriptor_;
}
bool FailSignal_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}


// ===================================================================

#ifndef _MSC_VER
const int PacketHeader::kSizeFieldNumber;
const int PacketHeader::kTypeFieldNumber;
#endif  // !_MSC_VER

PacketHeader::PacketHeader()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protocol.PacketHeader)
}

void PacketHeader::InitAsDefaultInstance() {
}

PacketHeader::PacketHeader(const PacketHeader& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:protocol.PacketHeader)
}

void PacketHeader::SharedCtor() {
  _cached_size_ = 0;
  size_ = 0u;
  type_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

PacketHeader::~PacketHeader() {
  // @@protoc_insertion_point(destructor:protocol.PacketHeader)
  SharedDtor();
}

void PacketHeader::SharedDtor() {
  if (this != default_instance_) {
  }
}

void PacketHeader::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* PacketHeader::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return PacketHeader_descriptor_;
}

const PacketHeader& PacketHeader::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RoomPacket_2eProto();
  return *default_instance_;
}

PacketHeader* PacketHeader::default_instance_ = NULL;

PacketHeader* PacketHeader::New() const {
  return new PacketHeader;
}

void PacketHeader::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<PacketHeader*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  ZR_(size_, type_);

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool PacketHeader::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protocol.PacketHeader)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional fixed32 size = 1;
      case 1: {
        if (tag == 13) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &size_)));
          set_has_size();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(21)) goto parse_type;
        break;
      }

      // optional fixed32 type = 2;
      case 2: {
        if (tag == 21) {
         parse_type:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED32>(
                 input, &type_)));
          set_has_type();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:protocol.PacketHeader)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protocol.PacketHeader)
  return false;
#undef DO_
}

void PacketHeader::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protocol.PacketHeader)
  // optional fixed32 size = 1;
  if (has_size()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(1, this->size(), output);
  }

  // optional fixed32 type = 2;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed32(2, this->type(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:protocol.PacketHeader)
}

::google::protobuf::uint8* PacketHeader::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.PacketHeader)
  // optional fixed32 size = 1;
  if (has_size()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(1, this->size(), target);
  }

  // optional fixed32 type = 2;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed32ToArray(2, this->type(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.PacketHeader)
  return target;
}

int PacketHeader::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional fixed32 size = 1;
    if (has_size()) {
      total_size += 1 + 4;
    }

    // optional fixed32 type = 2;
    if (has_type()) {
      total_size += 1 + 4;
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void PacketHeader::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const PacketHeader* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const PacketHeader*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void PacketHeader::MergeFrom(const PacketHeader& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_size()) {
      set_size(from.size());
    }
    if (from.has_type()) {
      set_type(from.type());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void PacketHeader::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PacketHeader::CopyFrom(const PacketHeader& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PacketHeader::IsInitialized() const {

  return true;
}

void PacketHeader::Swap(PacketHeader* other) {
  if (other != this) {
    std::swap(size_, other->size_);
    std::swap(type_, other->type_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata PacketHeader::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = PacketHeader_descriptor_;
  metadata.reflection = PacketHeader_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int RoomInfo::kRoomNumFieldNumber;
#endif  // !_MSC_VER

RoomInfo::RoomInfo()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protocol.RoomInfo)
}

void RoomInfo::InitAsDefaultInstance() {
}

RoomInfo::RoomInfo(const RoomInfo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:protocol.RoomInfo)
}

void RoomInfo::SharedCtor() {
  _cached_size_ = 0;
  roomnum_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

RoomInfo::~RoomInfo() {
  // @@protoc_insertion_point(destructor:protocol.RoomInfo)
  SharedDtor();
}

void RoomInfo::SharedDtor() {
  if (this != default_instance_) {
  }
}

void RoomInfo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* RoomInfo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return RoomInfo_descriptor_;
}

const RoomInfo& RoomInfo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RoomPacket_2eProto();
  return *default_instance_;
}

RoomInfo* RoomInfo::default_instance_ = NULL;

RoomInfo* RoomInfo::New() const {
  return new RoomInfo;
}

void RoomInfo::Clear() {
  roomnum_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool RoomInfo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protocol.RoomInfo)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 roomNum = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &roomnum_)));
          set_has_roomnum();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:protocol.RoomInfo)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protocol.RoomInfo)
  return false;
#undef DO_
}

void RoomInfo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protocol.RoomInfo)
  // optional uint32 roomNum = 1;
  if (has_roomnum()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->roomnum(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:protocol.RoomInfo)
}

::google::protobuf::uint8* RoomInfo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.RoomInfo)
  // optional uint32 roomNum = 1;
  if (has_roomnum()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->roomnum(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.RoomInfo)
  return target;
}

int RoomInfo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint32 roomNum = 1;
    if (has_roomnum()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->roomnum());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void RoomInfo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const RoomInfo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const RoomInfo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void RoomInfo::MergeFrom(const RoomInfo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_roomnum()) {
      set_roomnum(from.roomnum());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void RoomInfo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void RoomInfo::CopyFrom(const RoomInfo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool RoomInfo::IsInitialized() const {

  return true;
}

void RoomInfo::Swap(RoomInfo* other) {
  if (other != this) {
    std::swap(roomnum_, other->roomnum_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata RoomInfo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = RoomInfo_descriptor_;
  metadata.reflection = RoomInfo_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int CS_contact_alram::kNickNameFieldNumber;
const int CS_contact_alram::kSecurityCodeFieldNumber;
#endif  // !_MSC_VER

CS_contact_alram::CS_contact_alram()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protocol.CS_contact_alram)
}

void CS_contact_alram::InitAsDefaultInstance() {
}

CS_contact_alram::CS_contact_alram(const CS_contact_alram& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:protocol.CS_contact_alram)
}

void CS_contact_alram::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  nickname_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  securitycode_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CS_contact_alram::~CS_contact_alram() {
  // @@protoc_insertion_point(destructor:protocol.CS_contact_alram)
  SharedDtor();
}

void CS_contact_alram::SharedDtor() {
  if (nickname_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete nickname_;
  }
  if (securitycode_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete securitycode_;
  }
  if (this != default_instance_) {
  }
}

void CS_contact_alram::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CS_contact_alram::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CS_contact_alram_descriptor_;
}

const CS_contact_alram& CS_contact_alram::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RoomPacket_2eProto();
  return *default_instance_;
}

CS_contact_alram* CS_contact_alram::default_instance_ = NULL;

CS_contact_alram* CS_contact_alram::New() const {
  return new CS_contact_alram;
}

void CS_contact_alram::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_nickname()) {
      if (nickname_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        nickname_->clear();
      }
    }
    if (has_securitycode()) {
      if (securitycode_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        securitycode_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CS_contact_alram::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protocol.CS_contact_alram)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string nickName = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_nickname()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->nickname().data(), this->nickname().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "nickname");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_securityCode;
        break;
      }

      // optional string securityCode = 2;
      case 2: {
        if (tag == 18) {
         parse_securityCode:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_securitycode()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->securitycode().data(), this->securitycode().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "securitycode");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:protocol.CS_contact_alram)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protocol.CS_contact_alram)
  return false;
#undef DO_
}

void CS_contact_alram::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protocol.CS_contact_alram)
  // required string nickName = 1;
  if (has_nickname()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->nickname().data(), this->nickname().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "nickname");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->nickname(), output);
  }

  // optional string securityCode = 2;
  if (has_securitycode()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->securitycode().data(), this->securitycode().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "securitycode");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->securitycode(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:protocol.CS_contact_alram)
}

::google::protobuf::uint8* CS_contact_alram::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.CS_contact_alram)
  // required string nickName = 1;
  if (has_nickname()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->nickname().data(), this->nickname().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "nickname");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->nickname(), target);
  }

  // optional string securityCode = 2;
  if (has_securitycode()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->securitycode().data(), this->securitycode().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "securitycode");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->securitycode(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.CS_contact_alram)
  return target;
}

int CS_contact_alram::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string nickName = 1;
    if (has_nickname()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->nickname());
    }

    // optional string securityCode = 2;
    if (has_securitycode()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->securitycode());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void CS_contact_alram::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CS_contact_alram* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CS_contact_alram*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CS_contact_alram::MergeFrom(const CS_contact_alram& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_nickname()) {
      set_nickname(from.nickname());
    }
    if (from.has_securitycode()) {
      set_securitycode(from.securitycode());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CS_contact_alram::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CS_contact_alram::CopyFrom(const CS_contact_alram& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CS_contact_alram::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  return true;
}

void CS_contact_alram::Swap(CS_contact_alram* other) {
  if (other != this) {
    std::swap(nickname_, other->nickname_);
    std::swap(securitycode_, other->securitycode_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CS_contact_alram::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CS_contact_alram_descriptor_;
  metadata.reflection = CS_contact_alram_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
#endif  // !_MSC_VER

CS_room_info_request::CS_room_info_request()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protocol.CS_room_info_request)
}

void CS_room_info_request::InitAsDefaultInstance() {
}

CS_room_info_request::CS_room_info_request(const CS_room_info_request& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:protocol.CS_room_info_request)
}

void CS_room_info_request::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CS_room_info_request::~CS_room_info_request() {
  // @@protoc_insertion_point(destructor:protocol.CS_room_info_request)
  SharedDtor();
}

void CS_room_info_request::SharedDtor() {
  if (this != default_instance_) {
  }
}

void CS_room_info_request::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CS_room_info_request::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CS_room_info_request_descriptor_;
}

const CS_room_info_request& CS_room_info_request::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RoomPacket_2eProto();
  return *default_instance_;
}

CS_room_info_request* CS_room_info_request::default_instance_ = NULL;

CS_room_info_request* CS_room_info_request::New() const {
  return new CS_room_info_request;
}

void CS_room_info_request::Clear() {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CS_room_info_request::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protocol.CS_room_info_request)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
  handle_unusual:
    if (tag == 0 ||
        ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
        ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
      goto success;
    }
    DO_(::google::protobuf::internal::WireFormat::SkipField(
          input, tag, mutable_unknown_fields()));
  }
success:
  // @@protoc_insertion_point(parse_success:protocol.CS_room_info_request)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protocol.CS_room_info_request)
  return false;
#undef DO_
}

void CS_room_info_request::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protocol.CS_room_info_request)
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:protocol.CS_room_info_request)
}

::google::protobuf::uint8* CS_room_info_request::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.CS_room_info_request)
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.CS_room_info_request)
  return target;
}

int CS_room_info_request::ByteSize() const {
  int total_size = 0;

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void CS_room_info_request::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CS_room_info_request* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CS_room_info_request*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CS_room_info_request::MergeFrom(const CS_room_info_request& from) {
  GOOGLE_CHECK_NE(&from, this);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CS_room_info_request::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CS_room_info_request::CopyFrom(const CS_room_info_request& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CS_room_info_request::IsInitialized() const {

  return true;
}

void CS_room_info_request::Swap(CS_room_info_request* other) {
  if (other != this) {
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CS_room_info_request::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CS_room_info_request_descriptor_;
  metadata.reflection = CS_room_info_request_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
#endif  // !_MSC_VER

CS_total_room_info_request::CS_total_room_info_request()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protocol.CS_total_room_info_request)
}

void CS_total_room_info_request::InitAsDefaultInstance() {
}

CS_total_room_info_request::CS_total_room_info_request(const CS_total_room_info_request& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:protocol.CS_total_room_info_request)
}

void CS_total_room_info_request::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CS_total_room_info_request::~CS_total_room_info_request() {
  // @@protoc_insertion_point(destructor:protocol.CS_total_room_info_request)
  SharedDtor();
}

void CS_total_room_info_request::SharedDtor() {
  if (this != default_instance_) {
  }
}

void CS_total_room_info_request::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CS_total_room_info_request::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CS_total_room_info_request_descriptor_;
}

const CS_total_room_info_request& CS_total_room_info_request::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RoomPacket_2eProto();
  return *default_instance_;
}

CS_total_room_info_request* CS_total_room_info_request::default_instance_ = NULL;

CS_total_room_info_request* CS_total_room_info_request::New() const {
  return new CS_total_room_info_request;
}

void CS_total_room_info_request::Clear() {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CS_total_room_info_request::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protocol.CS_total_room_info_request)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
  handle_unusual:
    if (tag == 0 ||
        ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
        ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
      goto success;
    }
    DO_(::google::protobuf::internal::WireFormat::SkipField(
          input, tag, mutable_unknown_fields()));
  }
success:
  // @@protoc_insertion_point(parse_success:protocol.CS_total_room_info_request)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protocol.CS_total_room_info_request)
  return false;
#undef DO_
}

void CS_total_room_info_request::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protocol.CS_total_room_info_request)
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:protocol.CS_total_room_info_request)
}

::google::protobuf::uint8* CS_total_room_info_request::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.CS_total_room_info_request)
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.CS_total_room_info_request)
  return target;
}

int CS_total_room_info_request::ByteSize() const {
  int total_size = 0;

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void CS_total_room_info_request::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CS_total_room_info_request* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CS_total_room_info_request*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CS_total_room_info_request::MergeFrom(const CS_total_room_info_request& from) {
  GOOGLE_CHECK_NE(&from, this);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CS_total_room_info_request::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CS_total_room_info_request::CopyFrom(const CS_total_room_info_request& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CS_total_room_info_request::IsInitialized() const {

  return true;
}

void CS_total_room_info_request::Swap(CS_total_room_info_request* other) {
  if (other != this) {
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CS_total_room_info_request::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CS_total_room_info_request_descriptor_;
  metadata.reflection = CS_total_room_info_request_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int CS_room_create::kRoomNumFieldNumber;
const int CS_room_create::kIdFieldNumber;
#endif  // !_MSC_VER

CS_room_create::CS_room_create()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protocol.CS_room_create)
}

void CS_room_create::InitAsDefaultInstance() {
}

CS_room_create::CS_room_create(const CS_room_create& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:protocol.CS_room_create)
}

void CS_room_create::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  roomnum_ = 0u;
  id_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CS_room_create::~CS_room_create() {
  // @@protoc_insertion_point(destructor:protocol.CS_room_create)
  SharedDtor();
}

void CS_room_create::SharedDtor() {
  if (id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete id_;
  }
  if (this != default_instance_) {
  }
}

void CS_room_create::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CS_room_create::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CS_room_create_descriptor_;
}

const CS_room_create& CS_room_create::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RoomPacket_2eProto();
  return *default_instance_;
}

CS_room_create* CS_room_create::default_instance_ = NULL;

CS_room_create* CS_room_create::New() const {
  return new CS_room_create;
}

void CS_room_create::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    roomnum_ = 0u;
    if (has_id()) {
      if (id_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        id_->clear();
      }
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CS_room_create::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protocol.CS_room_create)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 roomNum = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &roomnum_)));
          set_has_roomnum();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_id;
        break;
      }

      // optional string id = 2;
      case 2: {
        if (tag == 18) {
         parse_id:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_id()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->id().data(), this->id().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "id");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:protocol.CS_room_create)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protocol.CS_room_create)
  return false;
#undef DO_
}

void CS_room_create::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protocol.CS_room_create)
  // optional uint32 roomNum = 1;
  if (has_roomnum()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->roomnum(), output);
  }

  // optional string id = 2;
  if (has_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->id().data(), this->id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "id");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      2, this->id(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:protocol.CS_room_create)
}

::google::protobuf::uint8* CS_room_create::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.CS_room_create)
  // optional uint32 roomNum = 1;
  if (has_roomnum()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->roomnum(), target);
  }

  // optional string id = 2;
  if (has_id()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->id().data(), this->id().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "id");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->id(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.CS_room_create)
  return target;
}

int CS_room_create::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint32 roomNum = 1;
    if (has_roomnum()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->roomnum());
    }

    // optional string id = 2;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->id());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void CS_room_create::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CS_room_create* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CS_room_create*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CS_room_create::MergeFrom(const CS_room_create& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_roomnum()) {
      set_roomnum(from.roomnum());
    }
    if (from.has_id()) {
      set_id(from.id());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CS_room_create::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CS_room_create::CopyFrom(const CS_room_create& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CS_room_create::IsInitialized() const {

  return true;
}

void CS_room_create::Swap(CS_room_create* other) {
  if (other != this) {
    std::swap(roomnum_, other->roomnum_);
    std::swap(id_, other->id_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CS_room_create::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CS_room_create_descriptor_;
  metadata.reflection = CS_room_create_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int CS_room_join::kRoomNumFieldNumber;
#endif  // !_MSC_VER

CS_room_join::CS_room_join()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protocol.CS_room_join)
}

void CS_room_join::InitAsDefaultInstance() {
}

CS_room_join::CS_room_join(const CS_room_join& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:protocol.CS_room_join)
}

void CS_room_join::SharedCtor() {
  _cached_size_ = 0;
  roomnum_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CS_room_join::~CS_room_join() {
  // @@protoc_insertion_point(destructor:protocol.CS_room_join)
  SharedDtor();
}

void CS_room_join::SharedDtor() {
  if (this != default_instance_) {
  }
}

void CS_room_join::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CS_room_join::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CS_room_join_descriptor_;
}

const CS_room_join& CS_room_join::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RoomPacket_2eProto();
  return *default_instance_;
}

CS_room_join* CS_room_join::default_instance_ = NULL;

CS_room_join* CS_room_join::New() const {
  return new CS_room_join;
}

void CS_room_join::Clear() {
  roomnum_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CS_room_join::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protocol.CS_room_join)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 roomNum = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &roomnum_)));
          set_has_roomnum();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:protocol.CS_room_join)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protocol.CS_room_join)
  return false;
#undef DO_
}

void CS_room_join::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protocol.CS_room_join)
  // optional uint32 roomNum = 1;
  if (has_roomnum()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->roomnum(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:protocol.CS_room_join)
}

::google::protobuf::uint8* CS_room_join::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.CS_room_join)
  // optional uint32 roomNum = 1;
  if (has_roomnum()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->roomnum(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.CS_room_join)
  return target;
}

int CS_room_join::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint32 roomNum = 1;
    if (has_roomnum()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->roomnum());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void CS_room_join::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CS_room_join* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CS_room_join*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CS_room_join::MergeFrom(const CS_room_join& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_roomnum()) {
      set_roomnum(from.roomnum());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CS_room_join::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CS_room_join::CopyFrom(const CS_room_join& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CS_room_join::IsInitialized() const {

  return true;
}

void CS_room_join::Swap(CS_room_join* other) {
  if (other != this) {
    std::swap(roomnum_, other->roomnum_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CS_room_join::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CS_room_join_descriptor_;
  metadata.reflection = CS_room_join_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
#endif  // !_MSC_VER

CS_room_leave::CS_room_leave()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protocol.CS_room_leave)
}

void CS_room_leave::InitAsDefaultInstance() {
}

CS_room_leave::CS_room_leave(const CS_room_leave& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:protocol.CS_room_leave)
}

void CS_room_leave::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CS_room_leave::~CS_room_leave() {
  // @@protoc_insertion_point(destructor:protocol.CS_room_leave)
  SharedDtor();
}

void CS_room_leave::SharedDtor() {
  if (this != default_instance_) {
  }
}

void CS_room_leave::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CS_room_leave::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CS_room_leave_descriptor_;
}

const CS_room_leave& CS_room_leave::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RoomPacket_2eProto();
  return *default_instance_;
}

CS_room_leave* CS_room_leave::default_instance_ = NULL;

CS_room_leave* CS_room_leave::New() const {
  return new CS_room_leave;
}

void CS_room_leave::Clear() {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CS_room_leave::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protocol.CS_room_leave)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
  handle_unusual:
    if (tag == 0 ||
        ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
        ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
      goto success;
    }
    DO_(::google::protobuf::internal::WireFormat::SkipField(
          input, tag, mutable_unknown_fields()));
  }
success:
  // @@protoc_insertion_point(parse_success:protocol.CS_room_leave)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protocol.CS_room_leave)
  return false;
#undef DO_
}

void CS_room_leave::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protocol.CS_room_leave)
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:protocol.CS_room_leave)
}

::google::protobuf::uint8* CS_room_leave::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.CS_room_leave)
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.CS_room_leave)
  return target;
}

int CS_room_leave::ByteSize() const {
  int total_size = 0;

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void CS_room_leave::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CS_room_leave* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CS_room_leave*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CS_room_leave::MergeFrom(const CS_room_leave& from) {
  GOOGLE_CHECK_NE(&from, this);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CS_room_leave::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CS_room_leave::CopyFrom(const CS_room_leave& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CS_room_leave::IsInitialized() const {

  return true;
}

void CS_room_leave::Swap(CS_room_leave* other) {
  if (other != this) {
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CS_room_leave::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CS_room_leave_descriptor_;
  metadata.reflection = CS_room_leave_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
#endif  // !_MSC_VER

CS_request_ingame_start::CS_request_ingame_start()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protocol.CS_request_ingame_start)
}

void CS_request_ingame_start::InitAsDefaultInstance() {
}

CS_request_ingame_start::CS_request_ingame_start(const CS_request_ingame_start& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:protocol.CS_request_ingame_start)
}

void CS_request_ingame_start::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CS_request_ingame_start::~CS_request_ingame_start() {
  // @@protoc_insertion_point(destructor:protocol.CS_request_ingame_start)
  SharedDtor();
}

void CS_request_ingame_start::SharedDtor() {
  if (this != default_instance_) {
  }
}

void CS_request_ingame_start::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CS_request_ingame_start::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CS_request_ingame_start_descriptor_;
}

const CS_request_ingame_start& CS_request_ingame_start::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RoomPacket_2eProto();
  return *default_instance_;
}

CS_request_ingame_start* CS_request_ingame_start::default_instance_ = NULL;

CS_request_ingame_start* CS_request_ingame_start::New() const {
  return new CS_request_ingame_start;
}

void CS_request_ingame_start::Clear() {
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CS_request_ingame_start::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protocol.CS_request_ingame_start)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
  handle_unusual:
    if (tag == 0 ||
        ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
        ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
      goto success;
    }
    DO_(::google::protobuf::internal::WireFormat::SkipField(
          input, tag, mutable_unknown_fields()));
  }
success:
  // @@protoc_insertion_point(parse_success:protocol.CS_request_ingame_start)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protocol.CS_request_ingame_start)
  return false;
#undef DO_
}

void CS_request_ingame_start::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protocol.CS_request_ingame_start)
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:protocol.CS_request_ingame_start)
}

::google::protobuf::uint8* CS_request_ingame_start::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.CS_request_ingame_start)
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.CS_request_ingame_start)
  return target;
}

int CS_request_ingame_start::ByteSize() const {
  int total_size = 0;

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void CS_request_ingame_start::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CS_request_ingame_start* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CS_request_ingame_start*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CS_request_ingame_start::MergeFrom(const CS_request_ingame_start& from) {
  GOOGLE_CHECK_NE(&from, this);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CS_request_ingame_start::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CS_request_ingame_start::CopyFrom(const CS_request_ingame_start& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CS_request_ingame_start::IsInitialized() const {

  return true;
}

void CS_request_ingame_start::Swap(CS_request_ingame_start* other) {
  if (other != this) {
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CS_request_ingame_start::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CS_request_ingame_start_descriptor_;
  metadata.reflection = CS_request_ingame_start_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int SC_contact_result::kFailSignalFieldNumber;
#endif  // !_MSC_VER

SC_contact_result::SC_contact_result()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protocol.SC_contact_result)
}

void SC_contact_result::InitAsDefaultInstance() {
}

SC_contact_result::SC_contact_result(const SC_contact_result& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:protocol.SC_contact_result)
}

void SC_contact_result::SharedCtor() {
  _cached_size_ = 0;
  failsignal_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SC_contact_result::~SC_contact_result() {
  // @@protoc_insertion_point(destructor:protocol.SC_contact_result)
  SharedDtor();
}

void SC_contact_result::SharedDtor() {
  if (this != default_instance_) {
  }
}

void SC_contact_result::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SC_contact_result::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SC_contact_result_descriptor_;
}

const SC_contact_result& SC_contact_result::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RoomPacket_2eProto();
  return *default_instance_;
}

SC_contact_result* SC_contact_result::default_instance_ = NULL;

SC_contact_result* SC_contact_result::New() const {
  return new SC_contact_result;
}

void SC_contact_result::Clear() {
  failsignal_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SC_contact_result::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protocol.SC_contact_result)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .protocol.FailSignal failSignal = 1;
      case 1: {
        if (tag == 8) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::protocol::FailSignal_IsValid(value)) {
            set_failsignal(static_cast< ::protocol::FailSignal >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:protocol.SC_contact_result)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protocol.SC_contact_result)
  return false;
#undef DO_
}

void SC_contact_result::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protocol.SC_contact_result)
  // optional .protocol.FailSignal failSignal = 1;
  if (has_failsignal()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->failsignal(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:protocol.SC_contact_result)
}

::google::protobuf::uint8* SC_contact_result::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.SC_contact_result)
  // optional .protocol.FailSignal failSignal = 1;
  if (has_failsignal()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->failsignal(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.SC_contact_result)
  return target;
}

int SC_contact_result::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .protocol.FailSignal failSignal = 1;
    if (has_failsignal()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->failsignal());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SC_contact_result::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SC_contact_result* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SC_contact_result*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SC_contact_result::MergeFrom(const SC_contact_result& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_failsignal()) {
      set_failsignal(from.failsignal());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SC_contact_result::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SC_contact_result::CopyFrom(const SC_contact_result& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SC_contact_result::IsInitialized() const {

  return true;
}

void SC_contact_result::Swap(SC_contact_result* other) {
  if (other != this) {
    std::swap(failsignal_, other->failsignal_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SC_contact_result::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SC_contact_result_descriptor_;
  metadata.reflection = SC_contact_result_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int SC_room_info::kPlayerNickNamesFieldNumber;
#endif  // !_MSC_VER

SC_room_info::SC_room_info()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protocol.SC_room_info)
}

void SC_room_info::InitAsDefaultInstance() {
}

SC_room_info::SC_room_info(const SC_room_info& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:protocol.SC_room_info)
}

void SC_room_info::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SC_room_info::~SC_room_info() {
  // @@protoc_insertion_point(destructor:protocol.SC_room_info)
  SharedDtor();
}

void SC_room_info::SharedDtor() {
  if (this != default_instance_) {
  }
}

void SC_room_info::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SC_room_info::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SC_room_info_descriptor_;
}

const SC_room_info& SC_room_info::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RoomPacket_2eProto();
  return *default_instance_;
}

SC_room_info* SC_room_info::default_instance_ = NULL;

SC_room_info* SC_room_info::New() const {
  return new SC_room_info;
}

void SC_room_info::Clear() {
  playernicknames_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SC_room_info::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protocol.SC_room_info)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated string playerNickNames = 1;
      case 1: {
        if (tag == 10) {
         parse_playerNickNames:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->add_playernicknames()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->playernicknames(this->playernicknames_size() - 1).data(),
            this->playernicknames(this->playernicknames_size() - 1).length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "playernicknames");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_playerNickNames;
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:protocol.SC_room_info)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protocol.SC_room_info)
  return false;
#undef DO_
}

void SC_room_info::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protocol.SC_room_info)
  // repeated string playerNickNames = 1;
  for (int i = 0; i < this->playernicknames_size(); i++) {
  ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
    this->playernicknames(i).data(), this->playernicknames(i).length(),
    ::google::protobuf::internal::WireFormat::SERIALIZE,
    "playernicknames");
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->playernicknames(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:protocol.SC_room_info)
}

::google::protobuf::uint8* SC_room_info::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.SC_room_info)
  // repeated string playerNickNames = 1;
  for (int i = 0; i < this->playernicknames_size(); i++) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->playernicknames(i).data(), this->playernicknames(i).length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "playernicknames");
    target = ::google::protobuf::internal::WireFormatLite::
      WriteStringToArray(1, this->playernicknames(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.SC_room_info)
  return target;
}

int SC_room_info::ByteSize() const {
  int total_size = 0;

  // repeated string playerNickNames = 1;
  total_size += 1 * this->playernicknames_size();
  for (int i = 0; i < this->playernicknames_size(); i++) {
    total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
      this->playernicknames(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SC_room_info::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SC_room_info* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SC_room_info*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SC_room_info::MergeFrom(const SC_room_info& from) {
  GOOGLE_CHECK_NE(&from, this);
  playernicknames_.MergeFrom(from.playernicknames_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SC_room_info::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SC_room_info::CopyFrom(const SC_room_info& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SC_room_info::IsInitialized() const {

  return true;
}

void SC_room_info::Swap(SC_room_info* other) {
  if (other != this) {
    playernicknames_.Swap(&other->playernicknames_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SC_room_info::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SC_room_info_descriptor_;
  metadata.reflection = SC_room_info_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int SC_total_room_info::kRoomCountFieldNumber;
const int SC_total_room_info::kRoomListFieldNumber;
#endif  // !_MSC_VER

SC_total_room_info::SC_total_room_info()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protocol.SC_total_room_info)
}

void SC_total_room_info::InitAsDefaultInstance() {
}

SC_total_room_info::SC_total_room_info(const SC_total_room_info& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:protocol.SC_total_room_info)
}

void SC_total_room_info::SharedCtor() {
  _cached_size_ = 0;
  roomcount_ = 0u;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SC_total_room_info::~SC_total_room_info() {
  // @@protoc_insertion_point(destructor:protocol.SC_total_room_info)
  SharedDtor();
}

void SC_total_room_info::SharedDtor() {
  if (this != default_instance_) {
  }
}

void SC_total_room_info::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SC_total_room_info::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SC_total_room_info_descriptor_;
}

const SC_total_room_info& SC_total_room_info::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RoomPacket_2eProto();
  return *default_instance_;
}

SC_total_room_info* SC_total_room_info::default_instance_ = NULL;

SC_total_room_info* SC_total_room_info::New() const {
  return new SC_total_room_info;
}

void SC_total_room_info::Clear() {
  roomcount_ = 0u;
  roomlist_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SC_total_room_info::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protocol.SC_total_room_info)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional uint32 roomCount = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &roomcount_)));
          set_has_roomcount();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_roomList;
        break;
      }

      // repeated .protocol.RoomInfo roomList = 2;
      case 2: {
        if (tag == 18) {
         parse_roomList:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_roomlist()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_roomList;
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:protocol.SC_total_room_info)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protocol.SC_total_room_info)
  return false;
#undef DO_
}

void SC_total_room_info::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protocol.SC_total_room_info)
  // optional uint32 roomCount = 1;
  if (has_roomcount()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->roomcount(), output);
  }

  // repeated .protocol.RoomInfo roomList = 2;
  for (int i = 0; i < this->roomlist_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->roomlist(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:protocol.SC_total_room_info)
}

::google::protobuf::uint8* SC_total_room_info::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.SC_total_room_info)
  // optional uint32 roomCount = 1;
  if (has_roomcount()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->roomcount(), target);
  }

  // repeated .protocol.RoomInfo roomList = 2;
  for (int i = 0; i < this->roomlist_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->roomlist(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.SC_total_room_info)
  return target;
}

int SC_total_room_info::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional uint32 roomCount = 1;
    if (has_roomcount()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->roomcount());
    }

  }
  // repeated .protocol.RoomInfo roomList = 2;
  total_size += 1 * this->roomlist_size();
  for (int i = 0; i < this->roomlist_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->roomlist(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SC_total_room_info::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SC_total_room_info* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SC_total_room_info*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SC_total_room_info::MergeFrom(const SC_total_room_info& from) {
  GOOGLE_CHECK_NE(&from, this);
  roomlist_.MergeFrom(from.roomlist_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_roomcount()) {
      set_roomcount(from.roomcount());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SC_total_room_info::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SC_total_room_info::CopyFrom(const SC_total_room_info& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SC_total_room_info::IsInitialized() const {

  return true;
}

void SC_total_room_info::Swap(SC_total_room_info* other) {
  if (other != this) {
    std::swap(roomcount_, other->roomcount_);
    roomlist_.Swap(&other->roomlist_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SC_total_room_info::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SC_total_room_info_descriptor_;
  metadata.reflection = SC_total_room_info_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int SC_room_create_result::kFailSignalFieldNumber;
#endif  // !_MSC_VER

SC_room_create_result::SC_room_create_result()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protocol.SC_room_create_result)
}

void SC_room_create_result::InitAsDefaultInstance() {
}

SC_room_create_result::SC_room_create_result(const SC_room_create_result& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:protocol.SC_room_create_result)
}

void SC_room_create_result::SharedCtor() {
  _cached_size_ = 0;
  failsignal_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SC_room_create_result::~SC_room_create_result() {
  // @@protoc_insertion_point(destructor:protocol.SC_room_create_result)
  SharedDtor();
}

void SC_room_create_result::SharedDtor() {
  if (this != default_instance_) {
  }
}

void SC_room_create_result::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SC_room_create_result::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SC_room_create_result_descriptor_;
}

const SC_room_create_result& SC_room_create_result::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RoomPacket_2eProto();
  return *default_instance_;
}

SC_room_create_result* SC_room_create_result::default_instance_ = NULL;

SC_room_create_result* SC_room_create_result::New() const {
  return new SC_room_create_result;
}

void SC_room_create_result::Clear() {
  failsignal_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SC_room_create_result::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protocol.SC_room_create_result)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .protocol.FailSignal failSignal = 1;
      case 1: {
        if (tag == 8) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::protocol::FailSignal_IsValid(value)) {
            set_failsignal(static_cast< ::protocol::FailSignal >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:protocol.SC_room_create_result)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protocol.SC_room_create_result)
  return false;
#undef DO_
}

void SC_room_create_result::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protocol.SC_room_create_result)
  // optional .protocol.FailSignal failSignal = 1;
  if (has_failsignal()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->failsignal(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:protocol.SC_room_create_result)
}

::google::protobuf::uint8* SC_room_create_result::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.SC_room_create_result)
  // optional .protocol.FailSignal failSignal = 1;
  if (has_failsignal()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->failsignal(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.SC_room_create_result)
  return target;
}

int SC_room_create_result::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .protocol.FailSignal failSignal = 1;
    if (has_failsignal()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->failsignal());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SC_room_create_result::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SC_room_create_result* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SC_room_create_result*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SC_room_create_result::MergeFrom(const SC_room_create_result& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_failsignal()) {
      set_failsignal(from.failsignal());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SC_room_create_result::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SC_room_create_result::CopyFrom(const SC_room_create_result& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SC_room_create_result::IsInitialized() const {

  return true;
}

void SC_room_create_result::Swap(SC_room_create_result* other) {
  if (other != this) {
    std::swap(failsignal_, other->failsignal_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SC_room_create_result::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SC_room_create_result_descriptor_;
  metadata.reflection = SC_room_create_result_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int SC_room_join_result::kFailSignalFieldNumber;
#endif  // !_MSC_VER

SC_room_join_result::SC_room_join_result()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protocol.SC_room_join_result)
}

void SC_room_join_result::InitAsDefaultInstance() {
}

SC_room_join_result::SC_room_join_result(const SC_room_join_result& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:protocol.SC_room_join_result)
}

void SC_room_join_result::SharedCtor() {
  _cached_size_ = 0;
  failsignal_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SC_room_join_result::~SC_room_join_result() {
  // @@protoc_insertion_point(destructor:protocol.SC_room_join_result)
  SharedDtor();
}

void SC_room_join_result::SharedDtor() {
  if (this != default_instance_) {
  }
}

void SC_room_join_result::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SC_room_join_result::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SC_room_join_result_descriptor_;
}

const SC_room_join_result& SC_room_join_result::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RoomPacket_2eProto();
  return *default_instance_;
}

SC_room_join_result* SC_room_join_result::default_instance_ = NULL;

SC_room_join_result* SC_room_join_result::New() const {
  return new SC_room_join_result;
}

void SC_room_join_result::Clear() {
  failsignal_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SC_room_join_result::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protocol.SC_room_join_result)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .protocol.FailSignal failSignal = 1;
      case 1: {
        if (tag == 8) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::protocol::FailSignal_IsValid(value)) {
            set_failsignal(static_cast< ::protocol::FailSignal >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:protocol.SC_room_join_result)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protocol.SC_room_join_result)
  return false;
#undef DO_
}

void SC_room_join_result::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protocol.SC_room_join_result)
  // optional .protocol.FailSignal failSignal = 1;
  if (has_failsignal()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->failsignal(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:protocol.SC_room_join_result)
}

::google::protobuf::uint8* SC_room_join_result::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.SC_room_join_result)
  // optional .protocol.FailSignal failSignal = 1;
  if (has_failsignal()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->failsignal(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.SC_room_join_result)
  return target;
}

int SC_room_join_result::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .protocol.FailSignal failSignal = 1;
    if (has_failsignal()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->failsignal());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SC_room_join_result::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SC_room_join_result* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SC_room_join_result*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SC_room_join_result::MergeFrom(const SC_room_join_result& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_failsignal()) {
      set_failsignal(from.failsignal());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SC_room_join_result::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SC_room_join_result::CopyFrom(const SC_room_join_result& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SC_room_join_result::IsInitialized() const {

  return true;
}

void SC_room_join_result::Swap(SC_room_join_result* other) {
  if (other != this) {
    std::swap(failsignal_, other->failsignal_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SC_room_join_result::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SC_room_join_result_descriptor_;
  metadata.reflection = SC_room_join_result_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int SC_room_leave_result::kFailSignalFieldNumber;
#endif  // !_MSC_VER

SC_room_leave_result::SC_room_leave_result()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protocol.SC_room_leave_result)
}

void SC_room_leave_result::InitAsDefaultInstance() {
}

SC_room_leave_result::SC_room_leave_result(const SC_room_leave_result& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:protocol.SC_room_leave_result)
}

void SC_room_leave_result::SharedCtor() {
  _cached_size_ = 0;
  failsignal_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SC_room_leave_result::~SC_room_leave_result() {
  // @@protoc_insertion_point(destructor:protocol.SC_room_leave_result)
  SharedDtor();
}

void SC_room_leave_result::SharedDtor() {
  if (this != default_instance_) {
  }
}

void SC_room_leave_result::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SC_room_leave_result::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SC_room_leave_result_descriptor_;
}

const SC_room_leave_result& SC_room_leave_result::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RoomPacket_2eProto();
  return *default_instance_;
}

SC_room_leave_result* SC_room_leave_result::default_instance_ = NULL;

SC_room_leave_result* SC_room_leave_result::New() const {
  return new SC_room_leave_result;
}

void SC_room_leave_result::Clear() {
  failsignal_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SC_room_leave_result::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protocol.SC_room_leave_result)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .protocol.FailSignal failSignal = 1;
      case 1: {
        if (tag == 8) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::protocol::FailSignal_IsValid(value)) {
            set_failsignal(static_cast< ::protocol::FailSignal >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:protocol.SC_room_leave_result)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protocol.SC_room_leave_result)
  return false;
#undef DO_
}

void SC_room_leave_result::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protocol.SC_room_leave_result)
  // optional .protocol.FailSignal failSignal = 1;
  if (has_failsignal()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->failsignal(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:protocol.SC_room_leave_result)
}

::google::protobuf::uint8* SC_room_leave_result::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.SC_room_leave_result)
  // optional .protocol.FailSignal failSignal = 1;
  if (has_failsignal()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->failsignal(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.SC_room_leave_result)
  return target;
}

int SC_room_leave_result::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .protocol.FailSignal failSignal = 1;
    if (has_failsignal()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->failsignal());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SC_room_leave_result::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SC_room_leave_result* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SC_room_leave_result*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SC_room_leave_result::MergeFrom(const SC_room_leave_result& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_failsignal()) {
      set_failsignal(from.failsignal());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SC_room_leave_result::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SC_room_leave_result::CopyFrom(const SC_room_leave_result& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SC_room_leave_result::IsInitialized() const {

  return true;
}

void SC_room_leave_result::Swap(SC_room_leave_result* other) {
  if (other != this) {
    std::swap(failsignal_, other->failsignal_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SC_room_leave_result::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SC_room_leave_result_descriptor_;
  metadata.reflection = SC_room_leave_result_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int SC_ingame_start_result::kFailSignalFieldNumber;
#endif  // !_MSC_VER

SC_ingame_start_result::SC_ingame_start_result()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:protocol.SC_ingame_start_result)
}

void SC_ingame_start_result::InitAsDefaultInstance() {
}

SC_ingame_start_result::SC_ingame_start_result(const SC_ingame_start_result& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:protocol.SC_ingame_start_result)
}

void SC_ingame_start_result::SharedCtor() {
  _cached_size_ = 0;
  failsignal_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SC_ingame_start_result::~SC_ingame_start_result() {
  // @@protoc_insertion_point(destructor:protocol.SC_ingame_start_result)
  SharedDtor();
}

void SC_ingame_start_result::SharedDtor() {
  if (this != default_instance_) {
  }
}

void SC_ingame_start_result::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SC_ingame_start_result::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SC_ingame_start_result_descriptor_;
}

const SC_ingame_start_result& SC_ingame_start_result::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_RoomPacket_2eProto();
  return *default_instance_;
}

SC_ingame_start_result* SC_ingame_start_result::default_instance_ = NULL;

SC_ingame_start_result* SC_ingame_start_result::New() const {
  return new SC_ingame_start_result;
}

void SC_ingame_start_result::Clear() {
  failsignal_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SC_ingame_start_result::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:protocol.SC_ingame_start_result)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .protocol.FailSignal failSignal = 1;
      case 1: {
        if (tag == 8) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::protocol::FailSignal_IsValid(value)) {
            set_failsignal(static_cast< ::protocol::FailSignal >(value));
          } else {
            mutable_unknown_fields()->AddVarint(1, value);
          }
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:protocol.SC_ingame_start_result)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:protocol.SC_ingame_start_result)
  return false;
#undef DO_
}

void SC_ingame_start_result::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:protocol.SC_ingame_start_result)
  // optional .protocol.FailSignal failSignal = 1;
  if (has_failsignal()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->failsignal(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:protocol.SC_ingame_start_result)
}

::google::protobuf::uint8* SC_ingame_start_result::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:protocol.SC_ingame_start_result)
  // optional .protocol.FailSignal failSignal = 1;
  if (has_failsignal()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->failsignal(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:protocol.SC_ingame_start_result)
  return target;
}

int SC_ingame_start_result::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional .protocol.FailSignal failSignal = 1;
    if (has_failsignal()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->failsignal());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SC_ingame_start_result::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SC_ingame_start_result* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SC_ingame_start_result*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SC_ingame_start_result::MergeFrom(const SC_ingame_start_result& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_failsignal()) {
      set_failsignal(from.failsignal());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SC_ingame_start_result::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SC_ingame_start_result::CopyFrom(const SC_ingame_start_result& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SC_ingame_start_result::IsInitialized() const {

  return true;
}

void SC_ingame_start_result::Swap(SC_ingame_start_result* other) {
  if (other != this) {
    std::swap(failsignal_, other->failsignal_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SC_ingame_start_result::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SC_ingame_start_result_descriptor_;
  metadata.reflection = SC_ingame_start_result_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol

// @@protoc_insertion_point(global_scope)