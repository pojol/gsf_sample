// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Avatar.proto

#ifndef PROTOBUF_Avatar_2eproto__INCLUDED
#define PROTOBUF_Avatar_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3002000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3002000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
namespace test {
class Avatar;
class AvatarDefaultTypeInternal;
extern AvatarDefaultTypeInternal _Avatar_default_instance_;
}  // namespace test

namespace test {

namespace protobuf_Avatar_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_Avatar_2eproto

// ===================================================================

class Avatar : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:test.Avatar) */ {
 public:
  Avatar();
  virtual ~Avatar();

  Avatar(const Avatar& from);

  inline Avatar& operator=(const Avatar& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Avatar& default_instance();

  static inline const Avatar* internal_default_instance() {
    return reinterpret_cast<const Avatar*>(
               &_Avatar_default_instance_);
  }

  void Swap(Avatar* other);

  // implements Message ----------------------------------------------

  inline Avatar* New() const PROTOBUF_FINAL { return New(NULL); }

  Avatar* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Avatar& from);
  void MergeFrom(const Avatar& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output)
      const PROTOBUF_FINAL {
    return InternalSerializeWithCachedSizesToArray(
        ::google::protobuf::io::CodedOutputStream::IsDefaultSerializationDeterministic(), output);
  }
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(Avatar* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string name = 2;
  bool has_name() const;
  void clear_name();
  static const int kNameFieldNumber = 2;
  const ::std::string& name() const;
  void set_name(const ::std::string& value);
  #if LANG_CXX11
  void set_name(::std::string&& value);
  #endif
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  ::std::string* mutable_name();
  ::std::string* release_name();
  void set_allocated_name(::std::string* name);

  // required int64 id = 1;
  bool has_id() const;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::int64 id() const;
  void set_id(::google::protobuf::int64 value);

  // required uint32 hp = 3;
  bool has_hp() const;
  void clear_hp();
  static const int kHpFieldNumber = 3;
  ::google::protobuf::uint32 hp() const;
  void set_hp(::google::protobuf::uint32 value);

  // required uint32 lv = 4;
  bool has_lv() const;
  void clear_lv();
  static const int kLvFieldNumber = 4;
  ::google::protobuf::uint32 lv() const;
  void set_lv(::google::protobuf::uint32 value);

  // required int64 loginTime = 5;
  bool has_logintime() const;
  void clear_logintime();
  static const int kLoginTimeFieldNumber = 5;
  ::google::protobuf::int64 logintime() const;
  void set_logintime(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:test.Avatar)
 private:
  void set_has_id();
  void clear_has_id();
  void set_has_name();
  void clear_has_name();
  void set_has_hp();
  void clear_has_hp();
  void set_has_lv();
  void clear_has_lv();
  void set_has_logintime();
  void clear_has_logintime();

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::internal::ArenaStringPtr name_;
  ::google::protobuf::int64 id_;
  ::google::protobuf::uint32 hp_;
  ::google::protobuf::uint32 lv_;
  ::google::protobuf::int64 logintime_;
  friend struct  protobuf_Avatar_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Avatar

// required int64 id = 1;
inline bool Avatar::has_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Avatar::set_has_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Avatar::clear_has_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Avatar::clear_id() {
  id_ = GOOGLE_LONGLONG(0);
  clear_has_id();
}
inline ::google::protobuf::int64 Avatar::id() const {
  // @@protoc_insertion_point(field_get:test.Avatar.id)
  return id_;
}
inline void Avatar::set_id(::google::protobuf::int64 value) {
  set_has_id();
  id_ = value;
  // @@protoc_insertion_point(field_set:test.Avatar.id)
}

// required string name = 2;
inline bool Avatar::has_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Avatar::set_has_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Avatar::clear_has_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Avatar::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  clear_has_name();
}
inline const ::std::string& Avatar::name() const {
  // @@protoc_insertion_point(field_get:test.Avatar.name)
  return name_.GetNoArena();
}
inline void Avatar::set_name(const ::std::string& value) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:test.Avatar.name)
}
#if LANG_CXX11
inline void Avatar::set_name(::std::string&& value) {
  set_has_name();
  name_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:test.Avatar.name)
}
#endif
inline void Avatar::set_name(const char* value) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:test.Avatar.name)
}
inline void Avatar::set_name(const char* value, size_t size) {
  set_has_name();
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:test.Avatar.name)
}
inline ::std::string* Avatar::mutable_name() {
  set_has_name();
  // @@protoc_insertion_point(field_mutable:test.Avatar.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Avatar::release_name() {
  // @@protoc_insertion_point(field_release:test.Avatar.name)
  clear_has_name();
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Avatar::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    set_has_name();
  } else {
    clear_has_name();
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:test.Avatar.name)
}

// required uint32 hp = 3;
inline bool Avatar::has_hp() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void Avatar::set_has_hp() {
  _has_bits_[0] |= 0x00000004u;
}
inline void Avatar::clear_has_hp() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void Avatar::clear_hp() {
  hp_ = 0u;
  clear_has_hp();
}
inline ::google::protobuf::uint32 Avatar::hp() const {
  // @@protoc_insertion_point(field_get:test.Avatar.hp)
  return hp_;
}
inline void Avatar::set_hp(::google::protobuf::uint32 value) {
  set_has_hp();
  hp_ = value;
  // @@protoc_insertion_point(field_set:test.Avatar.hp)
}

// required uint32 lv = 4;
inline bool Avatar::has_lv() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void Avatar::set_has_lv() {
  _has_bits_[0] |= 0x00000008u;
}
inline void Avatar::clear_has_lv() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void Avatar::clear_lv() {
  lv_ = 0u;
  clear_has_lv();
}
inline ::google::protobuf::uint32 Avatar::lv() const {
  // @@protoc_insertion_point(field_get:test.Avatar.lv)
  return lv_;
}
inline void Avatar::set_lv(::google::protobuf::uint32 value) {
  set_has_lv();
  lv_ = value;
  // @@protoc_insertion_point(field_set:test.Avatar.lv)
}

// required int64 loginTime = 5;
inline bool Avatar::has_logintime() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void Avatar::set_has_logintime() {
  _has_bits_[0] |= 0x00000010u;
}
inline void Avatar::clear_has_logintime() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void Avatar::clear_logintime() {
  logintime_ = GOOGLE_LONGLONG(0);
  clear_has_logintime();
}
inline ::google::protobuf::int64 Avatar::logintime() const {
  // @@protoc_insertion_point(field_get:test.Avatar.loginTime)
  return logintime_;
}
inline void Avatar::set_logintime(::google::protobuf::int64 value) {
  set_has_logintime();
  logintime_ = value;
  // @@protoc_insertion_point(field_set:test.Avatar.loginTime)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace test

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Avatar_2eproto__INCLUDED
