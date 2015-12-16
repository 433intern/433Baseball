#ifndef PROTOBUF_IngamePacket_2ePROTO__INCLUDED
#define PROTOBUF_IngamePacket_2ePROTO__INCLUDED

namespace protocol {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_IngamePacket_2ePROTO();
void protobuf_AssignDesc_IngamePacket_2ePROTO();
void protobuf_ShutdownFile_IngamePacket_2ePROTO();

class CS_send_baseball_number;
class SC_receive_baseball_number_result;
class SC_give_turn;
class SC_wait_turn;
class SC_ingame_end;

enum PacketType {
  CS_SEND_BASEBALL_NUMBER = 15,
  SC_RECEIVE_BASEBALL_NUMBER_RESULT = 16,
  SC_GIVE_TURN = 17,
  SC_WAIT_TURN = 18,
  SC_INGAME_END = 19
};
bool PacketType_IsValid(int value);
const PacketType PacketType_MIN = CS_SEND_BASEBALL_NUMBER;
const PacketType PacketType_MAX = SC_INGAME_END;
const int PacketType_ARRAYSIZE = PacketType_MAX + 1;

const ::google::protobuf::EnumDescriptor* PacketType_descriptor();
inline const ::std::string& PacketType_Name(PacketType value) {
  return ::google::protobuf::internal::NameOfEnum(
    PacketType_descriptor(), value);
}
inline bool PacketType_Parse(
    const ::std::string& name, PacketType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<PacketType>(
    PacketType_descriptor(), name, value);
}
// ===================================================================

class CS_send_baseball_number : public ::google::protobuf::Message {
 public:
  CS_send_baseball_number();
  virtual ~CS_send_baseball_number();

  CS_send_baseball_number(const CS_send_baseball_number& from);

  inline CS_send_baseball_number& operator=(const CS_send_baseball_number& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CS_send_baseball_number& default_instance();

  void Swap(CS_send_baseball_number* other);

  // implements Message ----------------------------------------------

  CS_send_baseball_number* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CS_send_baseball_number& from);
  void MergeFrom(const CS_send_baseball_number& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint32 baseballNum = 1;
  inline bool has_baseballnum() const;
  inline void clear_baseballnum();
  static const int kBaseballNumFieldNumber = 1;
  inline ::google::protobuf::uint32 baseballnum() const;
  inline void set_baseballnum(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:protocol.CS_send_baseball_number)
 private:
  inline void set_has_baseballnum();
  inline void clear_has_baseballnum();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::uint32 baseballnum_;
  friend void  protobuf_AddDesc_IngamePacket_2ePROTO();
  friend void protobuf_AssignDesc_IngamePacket_2ePROTO();
  friend void protobuf_ShutdownFile_IngamePacket_2ePROTO();

  void InitAsDefaultInstance();
  static CS_send_baseball_number* default_instance_;
};
// -------------------------------------------------------------------

class SC_receive_baseball_number_result : public ::google::protobuf::Message {
 public:
  SC_receive_baseball_number_result();
  virtual ~SC_receive_baseball_number_result();

  SC_receive_baseball_number_result(const SC_receive_baseball_number_result& from);

  inline SC_receive_baseball_number_result& operator=(const SC_receive_baseball_number_result& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SC_receive_baseball_number_result& default_instance();

  void Swap(SC_receive_baseball_number_result* other);

  // implements Message ----------------------------------------------

  SC_receive_baseball_number_result* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SC_receive_baseball_number_result& from);
  void MergeFrom(const SC_receive_baseball_number_result& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint32 judgeStatus = 1;
  inline bool has_judgestatus() const;
  inline void clear_judgestatus();
  static const int kJudgeStatusFieldNumber = 1;
  inline ::google::protobuf::uint32 judgestatus() const;
  inline void set_judgestatus(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:protocol.SC_receive_baseball_number_result)
 private:
  inline void set_has_judgestatus();
  inline void clear_has_judgestatus();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::uint32 judgestatus_;
  friend void  protobuf_AddDesc_IngamePacket_2ePROTO();
  friend void protobuf_AssignDesc_IngamePacket_2ePROTO();
  friend void protobuf_ShutdownFile_IngamePacket_2ePROTO();

  void InitAsDefaultInstance();
  static SC_receive_baseball_number_result* default_instance_;
};
// -------------------------------------------------------------------

class SC_give_turn : public ::google::protobuf::Message {
 public:
  SC_give_turn();
  virtual ~SC_give_turn();

  SC_give_turn(const SC_give_turn& from);

  inline SC_give_turn& operator=(const SC_give_turn& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SC_give_turn& default_instance();

  void Swap(SC_give_turn* other);

  // implements Message ----------------------------------------------

  SC_give_turn* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SC_give_turn& from);
  void MergeFrom(const SC_give_turn& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:protocol.SC_give_turn)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_IngamePacket_2ePROTO();
  friend void protobuf_AssignDesc_IngamePacket_2ePROTO();
  friend void protobuf_ShutdownFile_IngamePacket_2ePROTO();

  void InitAsDefaultInstance();
  static SC_give_turn* default_instance_;
};
// -------------------------------------------------------------------

class SC_wait_turn : public ::google::protobuf::Message {
 public:
  SC_wait_turn();
  virtual ~SC_wait_turn();

  SC_wait_turn(const SC_wait_turn& from);

  inline SC_wait_turn& operator=(const SC_wait_turn& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SC_wait_turn& default_instance();

  void Swap(SC_wait_turn* other);

  // implements Message ----------------------------------------------

  SC_wait_turn* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SC_wait_turn& from);
  void MergeFrom(const SC_wait_turn& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:protocol.SC_wait_turn)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_IngamePacket_2ePROTO();
  friend void protobuf_AssignDesc_IngamePacket_2ePROTO();
  friend void protobuf_ShutdownFile_IngamePacket_2ePROTO();

  void InitAsDefaultInstance();
  static SC_wait_turn* default_instance_;
};
// -------------------------------------------------------------------

class SC_ingame_end : public ::google::protobuf::Message {
 public:
  SC_ingame_end();
  virtual ~SC_ingame_end();

  SC_ingame_end(const SC_ingame_end& from);

  inline SC_ingame_end& operator=(const SC_ingame_end& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SC_ingame_end& default_instance();

  void Swap(SC_ingame_end* other);

  // implements Message ----------------------------------------------

  SC_ingame_end* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SC_ingame_end& from);
  void MergeFrom(const SC_ingame_end& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional bool isWin = 1;
  inline bool has_iswin() const;
  inline void clear_iswin();
  static const int kIsWinFieldNumber = 1;
  inline bool iswin() const;
  inline void set_iswin(bool value);

  // @@protoc_insertion_point(class_scope:protocol.SC_ingame_end)
 private:
  inline void set_has_iswin();
  inline void clear_has_iswin();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  bool iswin_;
  friend void  protobuf_AddDesc_IngamePacket_2ePROTO();
  friend void protobuf_AssignDesc_IngamePacket_2ePROTO();
  friend void protobuf_ShutdownFile_IngamePacket_2ePROTO();

  void InitAsDefaultInstance();
  static SC_ingame_end* default_instance_;
};
// ===================================================================


// ===================================================================

// CS_send_baseball_number

// optional uint32 baseballNum = 1;
inline bool CS_send_baseball_number::has_baseballnum() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CS_send_baseball_number::set_has_baseballnum() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CS_send_baseball_number::clear_has_baseballnum() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CS_send_baseball_number::clear_baseballnum() {
  baseballnum_ = 0u;
  clear_has_baseballnum();
}
inline ::google::protobuf::uint32 CS_send_baseball_number::baseballnum() const {
  // @@protoc_insertion_point(field_get:protocol.CS_send_baseball_number.baseballNum)
  return baseballnum_;
}
inline void CS_send_baseball_number::set_baseballnum(::google::protobuf::uint32 value) {
  set_has_baseballnum();
  baseballnum_ = value;
  // @@protoc_insertion_point(field_set:protocol.CS_send_baseball_number.baseballNum)
}

// -------------------------------------------------------------------

// SC_receive_baseball_number_result

// optional uint32 judgeStatus = 1;
inline bool SC_receive_baseball_number_result::has_judgestatus() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SC_receive_baseball_number_result::set_has_judgestatus() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SC_receive_baseball_number_result::clear_has_judgestatus() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SC_receive_baseball_number_result::clear_judgestatus() {
  judgestatus_ = 0u;
  clear_has_judgestatus();
}
inline ::google::protobuf::uint32 SC_receive_baseball_number_result::judgestatus() const {
  // @@protoc_insertion_point(field_get:protocol.SC_receive_baseball_number_result.judgeStatus)
  return judgestatus_;
}
inline void SC_receive_baseball_number_result::set_judgestatus(::google::protobuf::uint32 value) {
  set_has_judgestatus();
  judgestatus_ = value;
  // @@protoc_insertion_point(field_set:protocol.SC_receive_baseball_number_result.judgeStatus)
}

// -------------------------------------------------------------------

// SC_give_turn

// -------------------------------------------------------------------

// SC_wait_turn

// -------------------------------------------------------------------

// SC_ingame_end

// optional bool isWin = 1;
inline bool SC_ingame_end::has_iswin() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SC_ingame_end::set_has_iswin() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SC_ingame_end::clear_has_iswin() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SC_ingame_end::clear_iswin() {
  iswin_ = false;
  clear_has_iswin();
}
inline bool SC_ingame_end::iswin() const {
  // @@protoc_insertion_point(field_get:protocol.SC_ingame_end.isWin)
  return iswin_;
}
inline void SC_ingame_end::set_iswin(bool value) {
  set_has_iswin();
  iswin_ = value;
  // @@protoc_insertion_point(field_set:protocol.SC_ingame_end.isWin)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::protocol::PacketType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::protocol::PacketType>() {
  return ::protocol::PacketType_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_IngamePacket_2ePROTO__INCLUDED
