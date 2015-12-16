// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: GamePacketEnumeration.proto

package com.example.sonjoy.baseballgameclient.protocol;

public final class GamePacketEnumeration {
  private GamePacketEnumeration() {}
  public static void registerAllExtensions(
      com.google.protobuf.ExtensionRegistry registry) {
  }
  /**
   * Protobuf enum {@code protocol.PacketType}
   */
  public enum PacketType
      implements com.google.protobuf.ProtocolMessageEnum {
    /**
     * <code>UNKNOWN = 0;</code>
     */
    UNKNOWN(0, 0),
    /**
     * <code>CS_CONTACT_ALRAM = 1;</code>
     *
     * <pre>
     * LOBBY
     * </pre>
     */
    CS_CONTACT_ALRAM(1, 1),
    /**
     * <code>CS_ROOM_CREATE = 2;</code>
     */
    CS_ROOM_CREATE(2, 2),
    /**
     * <code>CS_ROOM_JOIN = 3;</code>
     */
    CS_ROOM_JOIN(3, 3),
    /**
     * <code>SC_CONTACT_RESULT = 4;</code>
     */
    SC_CONTACT_RESULT(4, 4),
    /**
     * <code>SC_ROOM_CREATE_RESULT = 5;</code>
     */
    SC_ROOM_CREATE_RESULT(5, 5),
    /**
     * <code>SC_ROOM_JOIN_RESULT = 6;</code>
     */
    SC_ROOM_JOIN_RESULT(6, 6),
    /**
     * <code>CS_ROOM_LEAVE = 7;</code>
     *
     * <pre>
     * ROOM
     * </pre>
     */
    CS_ROOM_LEAVE(7, 7),
    /**
     * <code>CS_REQUEST_INGAME_START = 8;</code>
     */
    CS_REQUEST_INGAME_START(8, 8),
    /**
     * <code>CS_ROOM_INFO_REQUEST = 9;</code>
     */
    CS_ROOM_INFO_REQUEST(9, 9),
    /**
     * <code>CS_TOTAL_ROOM_INFO_REQUEST = 10;</code>
     */
    CS_TOTAL_ROOM_INFO_REQUEST(10, 10),
    /**
     * <code>SC_ROOM_LEAVE_RESULT = 11;</code>
     */
    SC_ROOM_LEAVE_RESULT(11, 11),
    /**
     * <code>SC_INGAME_START_RESULT = 12;</code>
     */
    SC_INGAME_START_RESULT(12, 12),
    /**
     * <code>SC_ROOM_INFO = 13;</code>
     */
    SC_ROOM_INFO(13, 13),
    /**
     * <code>SC_TOTAL_ROOM_INFO = 14;</code>
     */
    SC_TOTAL_ROOM_INFO(14, 14),
    /**
     * <code>CS_SEND_BASEBALL_NUMBER = 15;</code>
     *
     * <pre>
     * INGAME
     * </pre>
     */
    CS_SEND_BASEBALL_NUMBER(15, 15),
    /**
     * <code>SC_RECEIVE_BASEBALL_NUMBER_RESULT = 16;</code>
     */
    SC_RECEIVE_BASEBALL_NUMBER_RESULT(16, 16),
    /**
     * <code>SC_GIVE_TURN = 17;</code>
     */
    SC_GIVE_TURN(17, 17),
    /**
     * <code>SC_WAIT_TURN = 18;</code>
     */
    SC_WAIT_TURN(18, 18),
    /**
     * <code>SC_INGAME_END = 19;</code>
     */
    SC_INGAME_END(19, 19),
    ;

    /**
     * <code>UNKNOWN = 0;</code>
     */
    public static final int UNKNOWN_VALUE = 0;
    /**
     * <code>CS_CONTACT_ALRAM = 1;</code>
     *
     * <pre>
     * LOBBY
     * </pre>
     */
    public static final int CS_CONTACT_ALRAM_VALUE = 1;
    /**
     * <code>CS_ROOM_CREATE = 2;</code>
     */
    public static final int CS_ROOM_CREATE_VALUE = 2;
    /**
     * <code>CS_ROOM_JOIN = 3;</code>
     */
    public static final int CS_ROOM_JOIN_VALUE = 3;
    /**
     * <code>SC_CONTACT_RESULT = 4;</code>
     */
    public static final int SC_CONTACT_RESULT_VALUE = 4;
    /**
     * <code>SC_ROOM_CREATE_RESULT = 5;</code>
     */
    public static final int SC_ROOM_CREATE_RESULT_VALUE = 5;
    /**
     * <code>SC_ROOM_JOIN_RESULT = 6;</code>
     */
    public static final int SC_ROOM_JOIN_RESULT_VALUE = 6;
    /**
     * <code>CS_ROOM_LEAVE = 7;</code>
     *
     * <pre>
     * ROOM
     * </pre>
     */
    public static final int CS_ROOM_LEAVE_VALUE = 7;
    /**
     * <code>CS_REQUEST_INGAME_START = 8;</code>
     */
    public static final int CS_REQUEST_INGAME_START_VALUE = 8;
    /**
     * <code>CS_ROOM_INFO_REQUEST = 9;</code>
     */
    public static final int CS_ROOM_INFO_REQUEST_VALUE = 9;
    /**
     * <code>CS_TOTAL_ROOM_INFO_REQUEST = 10;</code>
     */
    public static final int CS_TOTAL_ROOM_INFO_REQUEST_VALUE = 10;
    /**
     * <code>SC_ROOM_LEAVE_RESULT = 11;</code>
     */
    public static final int SC_ROOM_LEAVE_RESULT_VALUE = 11;
    /**
     * <code>SC_INGAME_START_RESULT = 12;</code>
     */
    public static final int SC_INGAME_START_RESULT_VALUE = 12;
    /**
     * <code>SC_ROOM_INFO = 13;</code>
     */
    public static final int SC_ROOM_INFO_VALUE = 13;
    /**
     * <code>SC_TOTAL_ROOM_INFO = 14;</code>
     */
    public static final int SC_TOTAL_ROOM_INFO_VALUE = 14;
    /**
     * <code>CS_SEND_BASEBALL_NUMBER = 15;</code>
     *
     * <pre>
     * INGAME
     * </pre>
     */
    public static final int CS_SEND_BASEBALL_NUMBER_VALUE = 15;
    /**
     * <code>SC_RECEIVE_BASEBALL_NUMBER_RESULT = 16;</code>
     */
    public static final int SC_RECEIVE_BASEBALL_NUMBER_RESULT_VALUE = 16;
    /**
     * <code>SC_GIVE_TURN = 17;</code>
     */
    public static final int SC_GIVE_TURN_VALUE = 17;
    /**
     * <code>SC_WAIT_TURN = 18;</code>
     */
    public static final int SC_WAIT_TURN_VALUE = 18;
    /**
     * <code>SC_INGAME_END = 19;</code>
     */
    public static final int SC_INGAME_END_VALUE = 19;


    public final int getNumber() { return value; }

    public static PacketType valueOf(int value) {
      switch (value) {
        case 0: return UNKNOWN;
        case 1: return CS_CONTACT_ALRAM;
        case 2: return CS_ROOM_CREATE;
        case 3: return CS_ROOM_JOIN;
        case 4: return SC_CONTACT_RESULT;
        case 5: return SC_ROOM_CREATE_RESULT;
        case 6: return SC_ROOM_JOIN_RESULT;
        case 7: return CS_ROOM_LEAVE;
        case 8: return CS_REQUEST_INGAME_START;
        case 9: return CS_ROOM_INFO_REQUEST;
        case 10: return CS_TOTAL_ROOM_INFO_REQUEST;
        case 11: return SC_ROOM_LEAVE_RESULT;
        case 12: return SC_INGAME_START_RESULT;
        case 13: return SC_ROOM_INFO;
        case 14: return SC_TOTAL_ROOM_INFO;
        case 15: return CS_SEND_BASEBALL_NUMBER;
        case 16: return SC_RECEIVE_BASEBALL_NUMBER_RESULT;
        case 17: return SC_GIVE_TURN;
        case 18: return SC_WAIT_TURN;
        case 19: return SC_INGAME_END;
        default: return null;
      }
    }

    public static com.google.protobuf.Internal.EnumLiteMap<PacketType>
        internalGetValueMap() {
      return internalValueMap;
    }
    private static com.google.protobuf.Internal.EnumLiteMap<PacketType>
        internalValueMap =
          new com.google.protobuf.Internal.EnumLiteMap<PacketType>() {
            public PacketType findValueByNumber(int number) {
              return PacketType.valueOf(number);
            }
          };

    public final com.google.protobuf.Descriptors.EnumValueDescriptor
        getValueDescriptor() {
      return getDescriptor().getValues().get(index);
    }
    public final com.google.protobuf.Descriptors.EnumDescriptor
        getDescriptorForType() {
      return getDescriptor();
    }
    public static final com.google.protobuf.Descriptors.EnumDescriptor
        getDescriptor() {
      return com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.getDescriptor().getEnumTypes().get(0);
    }

    private static final PacketType[] VALUES = values();

    public static PacketType valueOf(
        com.google.protobuf.Descriptors.EnumValueDescriptor desc) {
      if (desc.getType() != getDescriptor()) {
        throw new java.lang.IllegalArgumentException(
          "EnumValueDescriptor is not for this type.");
      }
      return VALUES[desc.getIndex()];
    }

    private final int index;
    private final int value;

    private PacketType(int index, int value) {
      this.index = index;
      this.value = value;
    }

    // @@protoc_insertion_point(enum_scope:protocol.PacketType)
  }

  /**
   * Protobuf enum {@code protocol.FailSignal}
   */
  public enum FailSignal
      implements com.google.protobuf.ProtocolMessageEnum {
    /**
     * <code>FS_SUCCESS = 0;</code>
     */
    FS_SUCCESS(0, 0),
    /**
     * <code>FS_NO_EXIST = 1;</code>
     */
    FS_NO_EXIST(1, 1),
    /**
     * <code>FS_FULL_ROOM = 2;</code>
     */
    FS_FULL_ROOM(2, 2),
    /**
     * <code>FS_EXIST_REPETITION_NUMBER = 3;</code>
     */
    FS_EXIST_REPETITION_NUMBER(3, 3),
    /**
     * <code>FS_ALREADY_EXIST = 4;</code>
     */
    FS_ALREADY_EXIST(4, 4),
    /**
     * <code>FS_OVERFLOW = 5;</code>
     */
    FS_OVERFLOW(5, 5),
    ;

    /**
     * <code>FS_SUCCESS = 0;</code>
     */
    public static final int FS_SUCCESS_VALUE = 0;
    /**
     * <code>FS_NO_EXIST = 1;</code>
     */
    public static final int FS_NO_EXIST_VALUE = 1;
    /**
     * <code>FS_FULL_ROOM = 2;</code>
     */
    public static final int FS_FULL_ROOM_VALUE = 2;
    /**
     * <code>FS_EXIST_REPETITION_NUMBER = 3;</code>
     */
    public static final int FS_EXIST_REPETITION_NUMBER_VALUE = 3;
    /**
     * <code>FS_ALREADY_EXIST = 4;</code>
     */
    public static final int FS_ALREADY_EXIST_VALUE = 4;
    /**
     * <code>FS_OVERFLOW = 5;</code>
     */
    public static final int FS_OVERFLOW_VALUE = 5;


    public final int getNumber() { return value; }

    public static FailSignal valueOf(int value) {
      switch (value) {
        case 0: return FS_SUCCESS;
        case 1: return FS_NO_EXIST;
        case 2: return FS_FULL_ROOM;
        case 3: return FS_EXIST_REPETITION_NUMBER;
        case 4: return FS_ALREADY_EXIST;
        case 5: return FS_OVERFLOW;
        default: return null;
      }
    }

    public static com.google.protobuf.Internal.EnumLiteMap<FailSignal>
        internalGetValueMap() {
      return internalValueMap;
    }
    private static com.google.protobuf.Internal.EnumLiteMap<FailSignal>
        internalValueMap =
          new com.google.protobuf.Internal.EnumLiteMap<FailSignal>() {
            public FailSignal findValueByNumber(int number) {
              return FailSignal.valueOf(number);
            }
          };

    public final com.google.protobuf.Descriptors.EnumValueDescriptor
        getValueDescriptor() {
      return getDescriptor().getValues().get(index);
    }
    public final com.google.protobuf.Descriptors.EnumDescriptor
        getDescriptorForType() {
      return getDescriptor();
    }
    public static final com.google.protobuf.Descriptors.EnumDescriptor
        getDescriptor() {
      return com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.getDescriptor().getEnumTypes().get(1);
    }

    private static final FailSignal[] VALUES = values();

    public static FailSignal valueOf(
        com.google.protobuf.Descriptors.EnumValueDescriptor desc) {
      if (desc.getType() != getDescriptor()) {
        throw new java.lang.IllegalArgumentException(
          "EnumValueDescriptor is not for this type.");
      }
      return VALUES[desc.getIndex()];
    }

    private final int index;
    private final int value;

    private FailSignal(int index, int value) {
      this.index = index;
      this.value = value;
    }

    // @@protoc_insertion_point(enum_scope:protocol.FailSignal)
  }

  public interface PacketHeaderOrBuilder extends
      // @@protoc_insertion_point(interface_extends:protocol.PacketHeader)
      com.google.protobuf.MessageOrBuilder {

    /**
     * <code>optional fixed32 size = 1;</code>
     */
    boolean hasSize();
    /**
     * <code>optional fixed32 size = 1;</code>
     */
    int getSize();

    /**
     * <code>optional fixed32 type = 2;</code>
     */
    boolean hasType();
    /**
     * <code>optional fixed32 type = 2;</code>
     */
    int getType();
  }
  /**
   * Protobuf type {@code protocol.PacketHeader}
   */
  public static final class PacketHeader extends
      com.google.protobuf.GeneratedMessage implements
      // @@protoc_insertion_point(message_implements:protocol.PacketHeader)
      PacketHeaderOrBuilder {
    // Use PacketHeader.newBuilder() to construct.
    private PacketHeader(com.google.protobuf.GeneratedMessage.Builder<?> builder) {
      super(builder);
      this.unknownFields = builder.getUnknownFields();
    }
    private PacketHeader(boolean noInit) { this.unknownFields = com.google.protobuf.UnknownFieldSet.getDefaultInstance(); }

    private static final PacketHeader defaultInstance;
    public static PacketHeader getDefaultInstance() {
      return defaultInstance;
    }

    public PacketHeader getDefaultInstanceForType() {
      return defaultInstance;
    }

    private final com.google.protobuf.UnknownFieldSet unknownFields;
    @java.lang.Override
    public final com.google.protobuf.UnknownFieldSet
        getUnknownFields() {
      return this.unknownFields;
    }
    private PacketHeader(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      initFields();
      int mutable_bitField0_ = 0;
      com.google.protobuf.UnknownFieldSet.Builder unknownFields =
          com.google.protobuf.UnknownFieldSet.newBuilder();
      try {
        boolean done = false;
        while (!done) {
          int tag = input.readTag();
          switch (tag) {
            case 0:
              done = true;
              break;
            default: {
              if (!parseUnknownField(input, unknownFields,
                                     extensionRegistry, tag)) {
                done = true;
              }
              break;
            }
            case 13: {
              bitField0_ |= 0x00000001;
              size_ = input.readFixed32();
              break;
            }
            case 21: {
              bitField0_ |= 0x00000002;
              type_ = input.readFixed32();
              break;
            }
          }
        }
      } catch (com.google.protobuf.InvalidProtocolBufferException e) {
        throw e.setUnfinishedMessage(this);
      } catch (java.io.IOException e) {
        throw new com.google.protobuf.InvalidProtocolBufferException(
            e.getMessage()).setUnfinishedMessage(this);
      } finally {
        this.unknownFields = unknownFields.build();
        makeExtensionsImmutable();
      }
    }
    public static final com.google.protobuf.Descriptors.Descriptor
        getDescriptor() {
      return com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.internal_static_protocol_PacketHeader_descriptor;
    }

    protected com.google.protobuf.GeneratedMessage.FieldAccessorTable
        internalGetFieldAccessorTable() {
      return com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.internal_static_protocol_PacketHeader_fieldAccessorTable
          .ensureFieldAccessorsInitialized(
              com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader.class, com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader.Builder.class);
    }

    public static com.google.protobuf.Parser<PacketHeader> PARSER =
        new com.google.protobuf.AbstractParser<PacketHeader>() {
      public PacketHeader parsePartialFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws com.google.protobuf.InvalidProtocolBufferException {
        return new PacketHeader(input, extensionRegistry);
      }
    };

    @java.lang.Override
    public com.google.protobuf.Parser<PacketHeader> getParserForType() {
      return PARSER;
    }

    private int bitField0_;
    public static final int SIZE_FIELD_NUMBER = 1;
    private int size_;
    /**
     * <code>optional fixed32 size = 1;</code>
     */
    public boolean hasSize() {
      return ((bitField0_ & 0x00000001) == 0x00000001);
    }
    /**
     * <code>optional fixed32 size = 1;</code>
     */
    public int getSize() {
      return size_;
    }

    public static final int TYPE_FIELD_NUMBER = 2;
    private int type_;
    /**
     * <code>optional fixed32 type = 2;</code>
     */
    public boolean hasType() {
      return ((bitField0_ & 0x00000002) == 0x00000002);
    }
    /**
     * <code>optional fixed32 type = 2;</code>
     */
    public int getType() {
      return type_;
    }

    private void initFields() {
      size_ = 0;
      type_ = 0;
    }
    private byte memoizedIsInitialized = -1;
    public final boolean isInitialized() {
      byte isInitialized = memoizedIsInitialized;
      if (isInitialized == 1) return true;
      if (isInitialized == 0) return false;

      memoizedIsInitialized = 1;
      return true;
    }

    public void writeTo(com.google.protobuf.CodedOutputStream output)
                        throws java.io.IOException {
      getSerializedSize();
      if (((bitField0_ & 0x00000001) == 0x00000001)) {
        output.writeFixed32(1, size_);
      }
      if (((bitField0_ & 0x00000002) == 0x00000002)) {
        output.writeFixed32(2, type_);
      }
      getUnknownFields().writeTo(output);
    }

    private int memoizedSerializedSize = -1;
    public int getSerializedSize() {
      int size = memoizedSerializedSize;
      if (size != -1) return size;

      size = 0;
      if (((bitField0_ & 0x00000001) == 0x00000001)) {
        size += com.google.protobuf.CodedOutputStream
          .computeFixed32Size(1, size_);
      }
      if (((bitField0_ & 0x00000002) == 0x00000002)) {
        size += com.google.protobuf.CodedOutputStream
          .computeFixed32Size(2, type_);
      }
      size += getUnknownFields().getSerializedSize();
      memoizedSerializedSize = size;
      return size;
    }

    private static final long serialVersionUID = 0L;
    @java.lang.Override
    protected java.lang.Object writeReplace()
        throws java.io.ObjectStreamException {
      return super.writeReplace();
    }

    public static com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader parseFrom(
        com.google.protobuf.ByteString data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader parseFrom(
        com.google.protobuf.ByteString data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader parseFrom(byte[] data)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data);
    }
    public static com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader parseFrom(
        byte[] data,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws com.google.protobuf.InvalidProtocolBufferException {
      return PARSER.parseFrom(data, extensionRegistry);
    }
    public static com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader parseFrom(java.io.InputStream input)
        throws java.io.IOException {
      return PARSER.parseFrom(input);
    }
    public static com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader parseFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseFrom(input, extensionRegistry);
    }
    public static com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader parseDelimitedFrom(java.io.InputStream input)
        throws java.io.IOException {
      return PARSER.parseDelimitedFrom(input);
    }
    public static com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader parseDelimitedFrom(
        java.io.InputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseDelimitedFrom(input, extensionRegistry);
    }
    public static com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader parseFrom(
        com.google.protobuf.CodedInputStream input)
        throws java.io.IOException {
      return PARSER.parseFrom(input);
    }
    public static com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader parseFrom(
        com.google.protobuf.CodedInputStream input,
        com.google.protobuf.ExtensionRegistryLite extensionRegistry)
        throws java.io.IOException {
      return PARSER.parseFrom(input, extensionRegistry);
    }

    public static Builder newBuilder() { return Builder.create(); }
    public Builder newBuilderForType() { return newBuilder(); }
    public static Builder newBuilder(com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader prototype) {
      return newBuilder().mergeFrom(prototype);
    }
    public Builder toBuilder() { return newBuilder(this); }

    @java.lang.Override
    protected Builder newBuilderForType(
        com.google.protobuf.GeneratedMessage.BuilderParent parent) {
      Builder builder = new Builder(parent);
      return builder;
    }
    /**
     * Protobuf type {@code protocol.PacketHeader}
     */
    public static final class Builder extends
        com.google.protobuf.GeneratedMessage.Builder<Builder> implements
        // @@protoc_insertion_point(builder_implements:protocol.PacketHeader)
        com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeaderOrBuilder {
      public static final com.google.protobuf.Descriptors.Descriptor
          getDescriptor() {
        return com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.internal_static_protocol_PacketHeader_descriptor;
      }

      protected com.google.protobuf.GeneratedMessage.FieldAccessorTable
          internalGetFieldAccessorTable() {
        return com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.internal_static_protocol_PacketHeader_fieldAccessorTable
            .ensureFieldAccessorsInitialized(
                com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader.class, com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader.Builder.class);
      }

      // Construct using com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader.newBuilder()
      private Builder() {
        maybeForceBuilderInitialization();
      }

      private Builder(
          com.google.protobuf.GeneratedMessage.BuilderParent parent) {
        super(parent);
        maybeForceBuilderInitialization();
      }
      private void maybeForceBuilderInitialization() {
        if (com.google.protobuf.GeneratedMessage.alwaysUseFieldBuilders) {
        }
      }
      private static Builder create() {
        return new Builder();
      }

      public Builder clear() {
        super.clear();
        size_ = 0;
        bitField0_ = (bitField0_ & ~0x00000001);
        type_ = 0;
        bitField0_ = (bitField0_ & ~0x00000002);
        return this;
      }

      public Builder clone() {
        return create().mergeFrom(buildPartial());
      }

      public com.google.protobuf.Descriptors.Descriptor
          getDescriptorForType() {
        return com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.internal_static_protocol_PacketHeader_descriptor;
      }

      public com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader getDefaultInstanceForType() {
        return com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader.getDefaultInstance();
      }

      public com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader build() {
        com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader result = buildPartial();
        if (!result.isInitialized()) {
          throw newUninitializedMessageException(result);
        }
        return result;
      }

      public com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader buildPartial() {
        com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader result = new com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader(this);
        int from_bitField0_ = bitField0_;
        int to_bitField0_ = 0;
        if (((from_bitField0_ & 0x00000001) == 0x00000001)) {
          to_bitField0_ |= 0x00000001;
        }
        result.size_ = size_;
        if (((from_bitField0_ & 0x00000002) == 0x00000002)) {
          to_bitField0_ |= 0x00000002;
        }
        result.type_ = type_;
        result.bitField0_ = to_bitField0_;
        onBuilt();
        return result;
      }

      public Builder mergeFrom(com.google.protobuf.Message other) {
        if (other instanceof com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader) {
          return mergeFrom((com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader)other);
        } else {
          super.mergeFrom(other);
          return this;
        }
      }

      public Builder mergeFrom(com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader other) {
        if (other == com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader.getDefaultInstance()) return this;
        if (other.hasSize()) {
          setSize(other.getSize());
        }
        if (other.hasType()) {
          setType(other.getType());
        }
        this.mergeUnknownFields(other.getUnknownFields());
        return this;
      }

      public final boolean isInitialized() {
        return true;
      }

      public Builder mergeFrom(
          com.google.protobuf.CodedInputStream input,
          com.google.protobuf.ExtensionRegistryLite extensionRegistry)
          throws java.io.IOException {
        com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader parsedMessage = null;
        try {
          parsedMessage = PARSER.parsePartialFrom(input, extensionRegistry);
        } catch (com.google.protobuf.InvalidProtocolBufferException e) {
          parsedMessage = (com.example.sonjoy.baseballgameclient.protocol.GamePacketEnumeration.PacketHeader) e.getUnfinishedMessage();
          throw e;
        } finally {
          if (parsedMessage != null) {
            mergeFrom(parsedMessage);
          }
        }
        return this;
      }
      private int bitField0_;

      private int size_ ;
      /**
       * <code>optional fixed32 size = 1;</code>
       */
      public boolean hasSize() {
        return ((bitField0_ & 0x00000001) == 0x00000001);
      }
      /**
       * <code>optional fixed32 size = 1;</code>
       */
      public int getSize() {
        return size_;
      }
      /**
       * <code>optional fixed32 size = 1;</code>
       */
      public Builder setSize(int value) {
        bitField0_ |= 0x00000001;
        size_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>optional fixed32 size = 1;</code>
       */
      public Builder clearSize() {
        bitField0_ = (bitField0_ & ~0x00000001);
        size_ = 0;
        onChanged();
        return this;
      }

      private int type_ ;
      /**
       * <code>optional fixed32 type = 2;</code>
       */
      public boolean hasType() {
        return ((bitField0_ & 0x00000002) == 0x00000002);
      }
      /**
       * <code>optional fixed32 type = 2;</code>
       */
      public int getType() {
        return type_;
      }
      /**
       * <code>optional fixed32 type = 2;</code>
       */
      public Builder setType(int value) {
        bitField0_ |= 0x00000002;
        type_ = value;
        onChanged();
        return this;
      }
      /**
       * <code>optional fixed32 type = 2;</code>
       */
      public Builder clearType() {
        bitField0_ = (bitField0_ & ~0x00000002);
        type_ = 0;
        onChanged();
        return this;
      }

      // @@protoc_insertion_point(builder_scope:protocol.PacketHeader)
    }

    static {
      defaultInstance = new PacketHeader(true);
      defaultInstance.initFields();
    }

    // @@protoc_insertion_point(class_scope:protocol.PacketHeader)
  }

  private static final com.google.protobuf.Descriptors.Descriptor
    internal_static_protocol_PacketHeader_descriptor;
  private static
    com.google.protobuf.GeneratedMessage.FieldAccessorTable
      internal_static_protocol_PacketHeader_fieldAccessorTable;

  public static com.google.protobuf.Descriptors.FileDescriptor
      getDescriptor() {
    return descriptor;
  }
  private static com.google.protobuf.Descriptors.FileDescriptor
      descriptor;
  static {
    java.lang.String[] descriptorData = {
      "\n\033GamePacketEnumeration.proto\022\010protocol\"" +
      "*\n\014PacketHeader\022\014\n\004size\030\001 \001(\007\022\014\n\004type\030\002 " +
      "\001(\007*\345\003\n\nPacketType\022\013\n\007UNKNOWN\020\000\022\024\n\020CS_CO" +
      "NTACT_ALRAM\020\001\022\022\n\016CS_ROOM_CREATE\020\002\022\020\n\014CS_" +
      "ROOM_JOIN\020\003\022\025\n\021SC_CONTACT_RESULT\020\004\022\031\n\025SC" +
      "_ROOM_CREATE_RESULT\020\005\022\027\n\023SC_ROOM_JOIN_RE" +
      "SULT\020\006\022\021\n\rCS_ROOM_LEAVE\020\007\022\033\n\027CS_REQUEST_" +
      "INGAME_START\020\010\022\030\n\024CS_ROOM_INFO_REQUEST\020\t" +
      "\022\036\n\032CS_TOTAL_ROOM_INFO_REQUEST\020\n\022\030\n\024SC_R" +
      "OOM_LEAVE_RESULT\020\013\022\032\n\026SC_INGAME_START_RE",
      "SULT\020\014\022\020\n\014SC_ROOM_INFO\020\r\022\026\n\022SC_TOTAL_ROO" +
      "M_INFO\020\016\022\033\n\027CS_SEND_BASEBALL_NUMBER\020\017\022%\n" +
      "!SC_RECEIVE_BASEBALL_NUMBER_RESULT\020\020\022\020\n\014" +
      "SC_GIVE_TURN\020\021\022\020\n\014SC_WAIT_TURN\020\022\022\021\n\rSC_I" +
      "NGAME_END\020\023*\206\001\n\nFailSignal\022\016\n\nFS_SUCCESS" +
      "\020\000\022\017\n\013FS_NO_EXIST\020\001\022\020\n\014FS_FULL_ROOM\020\002\022\036\n" +
      "\032FS_EXIST_REPETITION_NUMBER\020\003\022\024\n\020FS_ALRE" +
      "ADY_EXIST\020\004\022\017\n\013FS_OVERFLOW\020\005B0\n.com.exam" +
      "ple.sonjoy.baseballgameclient.protocol"
    };
    com.google.protobuf.Descriptors.FileDescriptor.InternalDescriptorAssigner assigner =
        new com.google.protobuf.Descriptors.FileDescriptor.    InternalDescriptorAssigner() {
          public com.google.protobuf.ExtensionRegistry assignDescriptors(
              com.google.protobuf.Descriptors.FileDescriptor root) {
            descriptor = root;
            return null;
          }
        };
    com.google.protobuf.Descriptors.FileDescriptor
      .internalBuildGeneratedFileFrom(descriptorData,
        new com.google.protobuf.Descriptors.FileDescriptor[] {
        }, assigner);
    internal_static_protocol_PacketHeader_descriptor =
      getDescriptor().getMessageTypes().get(0);
    internal_static_protocol_PacketHeader_fieldAccessorTable = new
      com.google.protobuf.GeneratedMessage.FieldAccessorTable(
        internal_static_protocol_PacketHeader_descriptor,
        new java.lang.String[] { "Size", "Type", });
  }

  // @@protoc_insertion_point(outer_class_scope)
}
