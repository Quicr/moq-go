// Generated from: draft-ietf-moq-transport-16_filters_edited.txt

#include "quicr/detail/messages.h"

namespace quicr::messages {
    // usings

    /*
     * RequestUpdate stream in
     */
    BytesSpan operator>>(BytesSpan buffer, RequestUpdate& msg)
    {
        buffer = buffer >> msg.request_id; // (i)  >> RequestID
        buffer = buffer >> msg.existing_request_id; // (i)  >> ExistingRequestID
        buffer = buffer >> msg.parameters; // (..)  >> Parameters
        return buffer;
    }

    /*
     * RequestUpdate stream out
     */
    Bytes& operator<<(Bytes& buffer, const RequestUpdate& msg)
    {
        Bytes payload;
        // fill out payload
        payload << msg.request_id; // (i)  << RequestID
        payload << msg.existing_request_id; // (i)  << ExistingRequestID
        payload << msg.parameters; // (..)  << Parameters

        // fill out buffer
        ControlMessage message;
        message.type = static_cast<std::uint64_t>(ControlMessageType::kRequestUpdate);
        message.payload = payload;
        buffer << message;
        return buffer;
    }


    /*
     * Subscribe stream in
     */
    BytesSpan operator>>(BytesSpan buffer, Subscribe& msg)
    {
        buffer = buffer >> msg.request_id; // (i)  >> RequestID
        buffer = buffer >> msg.track_namespace; // (tuple)  >> TrackNamespace
        buffer = buffer >> msg.track_name; // (..)  >> TrackName
        buffer = buffer >> msg.parameters; // (..)  >> Parameters
        return buffer;
    }

    /*
     * Subscribe stream out
     */
    Bytes& operator<<(Bytes& buffer, const Subscribe& msg)
    {
        Bytes payload;
        // fill out payload
        payload << msg.request_id; // (i)  << RequestID
        payload << msg.track_namespace; // (tuple)  << TrackNamespace
        payload << msg.track_name; // (..)  << TrackName
        payload << msg.parameters; // (..)  << Parameters

        // fill out buffer
        ControlMessage message;
        message.type = static_cast<std::uint64_t>(ControlMessageType::kSubscribe);
        message.payload = payload;
        buffer << message;
        return buffer;
    }


    /*
     * SubscribeOk stream in
     */
    BytesSpan operator>>(BytesSpan buffer, SubscribeOk& msg)
    {
        buffer = buffer >> msg.request_id; // (i)  >> RequestID
        buffer = buffer >> msg.track_alias; // (i)  >> TrackAlias
        buffer = buffer >> msg.parameters; // (..)  >> Parameters
        buffer = buffer >> msg.track_extensions; // (tuple)  >> TrackExtensions
        return buffer;
    }

    /*
     * SubscribeOk stream out
     */
    Bytes& operator<<(Bytes& buffer, const SubscribeOk& msg)
    {
        Bytes payload;
        // fill out payload
        payload << msg.request_id; // (i)  << RequestID
        payload << msg.track_alias; // (i)  << TrackAlias
        payload << msg.parameters; // (..)  << Parameters
        payload << msg.track_extensions; // (tuple)  << TrackExtensions

        // fill out buffer
        ControlMessage message;
        message.type = static_cast<std::uint64_t>(ControlMessageType::kSubscribeOk);
        message.payload = payload;
        buffer << message;
        return buffer;
    }


    /*
     * RequestError stream in
     */
    BytesSpan operator>>(BytesSpan buffer, RequestError& msg)
    {
        buffer = buffer >> msg.request_id; // (i)  >> RequestID
        buffer = buffer >> msg.error_code; // (i)  >> ErrorCode
        buffer = buffer >> msg.retry_interval; // (i)  >> RetryInterval
        buffer = buffer >> msg.error_reason; // (Reason Phrase)  >> ErrorReason
        return buffer;
    }

    /*
     * RequestError stream out
     */
    Bytes& operator<<(Bytes& buffer, const RequestError& msg)
    {
        Bytes payload;
        // fill out payload
        payload << msg.request_id; // (i)  << RequestID
        payload << msg.error_code; // (i)  << ErrorCode
        payload << msg.retry_interval; // (i)  << RetryInterval
        payload << msg.error_reason; // (Reason Phrase)  << ErrorReason

        // fill out buffer
        ControlMessage message;
        message.type = static_cast<std::uint64_t>(ControlMessageType::kRequestError);
        message.payload = payload;
        buffer << message;
        return buffer;
    }


    /*
     * PublishNamespace stream in
     */
    BytesSpan operator>>(BytesSpan buffer, PublishNamespace& msg)
    {
        buffer = buffer >> msg.request_id; // (i)  >> RequestID
        buffer = buffer >> msg.track_namespace; // (tuple)  >> TrackNamespace
        buffer = buffer >> msg.parameters; // (..)  >> Parameters
        return buffer;
    }

    /*
     * PublishNamespace stream out
     */
    Bytes& operator<<(Bytes& buffer, const PublishNamespace& msg)
    {
        Bytes payload;
        // fill out payload
        payload << msg.request_id; // (i)  << RequestID
        payload << msg.track_namespace; // (tuple)  << TrackNamespace
        payload << msg.parameters; // (..)  << Parameters

        // fill out buffer
        ControlMessage message;
        message.type = static_cast<std::uint64_t>(ControlMessageType::kPublishNamespace);
        message.payload = payload;
        buffer << message;
        return buffer;
    }


    /*
     * RequestOk stream in
     */
    BytesSpan operator>>(BytesSpan buffer, RequestOk& msg)
    {
        buffer = buffer >> msg.request_id; // (i)  >> RequestID
        buffer = buffer >> msg.parameters; // (..)  >> Parameters
        return buffer;
    }

    /*
     * RequestOk stream out
     */
    Bytes& operator<<(Bytes& buffer, const RequestOk& msg)
    {
        Bytes payload;
        // fill out payload
        payload << msg.request_id; // (i)  << RequestID
        payload << msg.parameters; // (..)  << Parameters

        // fill out buffer
        ControlMessage message;
        message.type = static_cast<std::uint64_t>(ControlMessageType::kRequestOk);
        message.payload = payload;
        buffer << message;
        return buffer;
    }


    /*
     * Namespace stream in
     */
    BytesSpan operator>>(BytesSpan buffer, Namespace& msg)
    {
        buffer = buffer >> msg.track_namespace_suffix; // (..)  >> TrackNamespaceSuffix
        return buffer;
    }

    /*
     * Namespace stream out
     */
    Bytes& operator<<(Bytes& buffer, const Namespace& msg)
    {
        Bytes payload;
        // fill out payload
        payload << msg.track_namespace_suffix; // (..)  << TrackNamespaceSuffix

        // fill out buffer
        ControlMessage message;
        message.type = static_cast<std::uint64_t>(ControlMessageType::kNamespace);
        message.payload = payload;
        buffer << message;
        return buffer;
    }


    /*
     * PublishNamespaceDone stream in
     */
    BytesSpan operator>>(BytesSpan buffer, PublishNamespaceDone& msg)
    {
        buffer = buffer >> msg.request_id; // (i)  >> RequestID
        return buffer;
    }

    /*
     * PublishNamespaceDone stream out
     */
    Bytes& operator<<(Bytes& buffer, const PublishNamespaceDone& msg)
    {
        Bytes payload;
        // fill out payload
        payload << msg.request_id; // (i)  << RequestID

        // fill out buffer
        ControlMessage message;
        message.type = static_cast<std::uint64_t>(ControlMessageType::kPublishNamespaceDone);
        message.payload = payload;
        buffer << message;
        return buffer;
    }


    /*
     * Unsubscribe stream in
     */
    BytesSpan operator>>(BytesSpan buffer, Unsubscribe& msg)
    {
        buffer = buffer >> msg.request_id; // (i)  >> RequestID
        return buffer;
    }

    /*
     * Unsubscribe stream out
     */
    Bytes& operator<<(Bytes& buffer, const Unsubscribe& msg)
    {
        Bytes payload;
        // fill out payload
        payload << msg.request_id; // (i)  << RequestID

        // fill out buffer
        ControlMessage message;
        message.type = static_cast<std::uint64_t>(ControlMessageType::kUnsubscribe);
        message.payload = payload;
        buffer << message;
        return buffer;
    }


    /*
     * PublishDone stream in
     */
    BytesSpan operator>>(BytesSpan buffer, PublishDone& msg)
    {
        buffer = buffer >> msg.request_id; // (i)  >> RequestID
        buffer = buffer >> msg.status_code; // (i)  >> PublishDoneStatusCode
        buffer = buffer >> msg.stream_count; // (i)  >> StreamCount
        buffer = buffer >> msg.error_reason; // (Reason Phrase)  >> ErrorReason
        return buffer;
    }

    /*
     * PublishDone stream out
     */
    Bytes& operator<<(Bytes& buffer, const PublishDone& msg)
    {
        Bytes payload;
        // fill out payload
        payload << msg.request_id; // (i)  << RequestID
        payload << msg.status_code; // (i)  << PublishDoneStatusCode
        payload << msg.stream_count; // (i)  << StreamCount
        payload << msg.error_reason; // (Reason Phrase)  << ErrorReason

        // fill out buffer
        ControlMessage message;
        message.type = static_cast<std::uint64_t>(ControlMessageType::kPublishDone);
        message.payload = payload;
        buffer << message;
        return buffer;
    }


    /*
     * PublishNamespaceCancel stream in
     */
    BytesSpan operator>>(BytesSpan buffer, PublishNamespaceCancel& msg)
    {
        buffer = buffer >> msg.request_id; // (i)  >> RequestID
        buffer = buffer >> msg.error_code; // (i)  >> ErrorCode
        buffer = buffer >> msg.error_reason; // (Reason Phrase)  >> ErrorReason
        return buffer;
    }

    /*
     * PublishNamespaceCancel stream out
     */
    Bytes& operator<<(Bytes& buffer, const PublishNamespaceCancel& msg)
    {
        Bytes payload;
        // fill out payload
        payload << msg.request_id; // (i)  << RequestID
        payload << msg.error_code; // (i)  << ErrorCode
        payload << msg.error_reason; // (Reason Phrase)  << ErrorReason

        // fill out buffer
        ControlMessage message;
        message.type = static_cast<std::uint64_t>(ControlMessageType::kPublishNamespaceCancel);
        message.payload = payload;
        buffer << message;
        return buffer;
    }


    /*
     * TrackStatus stream in
     */
    BytesSpan operator>>(BytesSpan buffer, TrackStatus& msg)
    {
        buffer = buffer >> msg.request_id; // (i)  >> RequestID
        buffer = buffer >> msg.track_namespace; // (tuple)  >> TrackNamespace
        buffer = buffer >> msg.track_name; // (..)  >> TrackName
        return buffer;
    }

    /*
     * TrackStatus stream out
     */
    Bytes& operator<<(Bytes& buffer, const TrackStatus& msg)
    {
        Bytes payload;
        // fill out payload
        payload << msg.request_id; // (i)  << RequestID
        payload << msg.track_namespace; // (tuple)  << TrackNamespace
        payload << msg.track_name; // (..)  << TrackName

        // fill out buffer
        ControlMessage message;
        message.type = static_cast<std::uint64_t>(ControlMessageType::kTrackStatus);
        message.payload = payload;
        buffer << message;
        return buffer;
    }


    /*
     * NamespaceDone stream in
     */
    BytesSpan operator>>(BytesSpan buffer, NamespaceDone& msg)
    {
        buffer = buffer >> msg.track_namespace_suffix; // (..)  >> TrackNamespaceSuffix
        return buffer;
    }

    /*
     * NamespaceDone stream out
     */
    Bytes& operator<<(Bytes& buffer, const NamespaceDone& msg)
    {
        Bytes payload;
        // fill out payload
        payload << msg.track_namespace_suffix; // (..)  << TrackNamespaceSuffix

        // fill out buffer
        ControlMessage message;
        message.type = static_cast<std::uint64_t>(ControlMessageType::kNamespaceDone);
        message.payload = payload;
        buffer << message;
        return buffer;
    }


    /*
     * Goaway stream in
     */
    BytesSpan operator>>(BytesSpan buffer, Goaway& msg)
    {
        buffer = buffer >> msg.new_session_uri; // (..)  >> NewSessionURI
        return buffer;
    }

    /*
     * Goaway stream out
     */
    Bytes& operator<<(Bytes& buffer, const Goaway& msg)
    {
        Bytes payload;
        // fill out payload
        payload << msg.new_session_uri; // (..)  << NewSessionURI

        // fill out buffer
        ControlMessage message;
        message.type = static_cast<std::uint64_t>(ControlMessageType::kGoaway);
        message.payload = payload;
        buffer << message;
        return buffer;
    }


    /*
     * SubscribeNamespace stream in
     */
    BytesSpan operator>>(BytesSpan buffer, SubscribeNamespace& msg)
    {
        buffer = buffer >> msg.request_id; // (i)  >> RequestID
        buffer = buffer >> msg.track_namespace_prefix; // (tuple)  >> TrackNamespacePrefix
        buffer = buffer >> msg.subscribe_options; // (i)  >> SubscribeOptions
        buffer = buffer >> msg.parameters; // (..)  >> Parameters
        return buffer;
    }

    /*
     * SubscribeNamespace stream out
     */
    Bytes& operator<<(Bytes& buffer, const SubscribeNamespace& msg)
    {
        Bytes payload;
        // fill out payload
        payload << msg.request_id; // (i)  << RequestID
        payload << msg.track_namespace_prefix; // (tuple)  << TrackNamespacePrefix
        payload << msg.subscribe_options; // (i)  << SubscribeOptions
        payload << msg.parameters; // (..)  << Parameters

        // fill out buffer
        ControlMessage message;
        message.type = static_cast<std::uint64_t>(ControlMessageType::kSubscribeNamespace);
        message.payload = payload;
        buffer << message;
        return buffer;
    }


    /*
     * MaxRequestId stream in
     */
    BytesSpan operator>>(BytesSpan buffer, MaxRequestId& msg)
    {
        buffer = buffer >> msg.max_request_id; // (i)  >> MaxRequestID
        return buffer;
    }

    /*
     * MaxRequestId stream out
     */
    Bytes& operator<<(Bytes& buffer, const MaxRequestId& msg)
    {
        Bytes payload;
        // fill out payload
        payload << msg.max_request_id; // (i)  << MaxRequestID

        // fill out buffer
        ControlMessage message;
        message.type = static_cast<std::uint64_t>(ControlMessageType::kMaxRequestId);
        message.payload = payload;
        buffer << message;
        return buffer;
    }

    /*
     * Fetch stream in constructor
     */
    Fetch::Fetch(
            std::function<void (Fetch&)> group_0_cb,
            std::function<void (Fetch&)> group_1_cb
        ):
            group_0_cb(group_0_cb),
            group_1_cb(group_1_cb)
    {
        if (group_0_cb == nullptr) {
            throw std::invalid_argument("Callbacks must be specified");
        }
        if (group_1_cb == nullptr) {
            throw std::invalid_argument("Callbacks must be specified");
        }
    }


    /*
     * Fetch stream in
     */
    BytesSpan operator>>(BytesSpan buffer, Fetch& msg)
    {
        buffer = buffer >> msg.request_id; // (i)  >> RequestID
        buffer = buffer >> msg.fetch_type; // (i)  >> FetchType
        if (msg.group_0_cb) { msg.group_0_cb(msg); }
        buffer = buffer >> msg.group_0; // (optional group)  >> Fetch::Group_0
        if (msg.group_1_cb) { msg.group_1_cb(msg); }
        buffer = buffer >> msg.group_1; // (optional group)  >> Fetch::Group_1
        buffer = buffer >> msg.parameters; // (..)  >> Parameters
        return buffer;
    }

    /*
     * Fetch stream out
     */
    Bytes& operator<<(Bytes& buffer, const Fetch& msg)
    {
        Bytes payload;
        // fill out payload
        payload << msg.request_id; // (i)  << RequestID
        payload << msg.fetch_type; // (i)  << FetchType
        payload << msg.group_0; // (optional group)  << Fetch::Group_0
        payload << msg.group_1; // (optional group)  << Fetch::Group_1
        payload << msg.parameters; // (..)  << Parameters

        // fill out buffer
        ControlMessage message;
        message.type = static_cast<std::uint64_t>(ControlMessageType::kFetch);
        message.payload = payload;
        buffer << message;
        return buffer;
    }

    BytesSpan operator>>(BytesSpan buffer, std::optional<Fetch::Group_0>& grp)
    {
        if (grp.has_value()) {
            buffer = buffer >> grp->standalone; // (Standalone Fetch) >> Standalone
        }
        return buffer;
    }  

    Bytes& operator<<(Bytes& buffer, const std::optional<Fetch::Group_0>& grp)
    {
        if (grp.has_value()) {
            buffer << grp->standalone; // (Standalone Fetch) << Standalone
        }
        return buffer;
    }
    BytesSpan operator>>(BytesSpan buffer, std::optional<Fetch::Group_1>& grp)
    {
        if (grp.has_value()) {
            buffer = buffer >> grp->joining; // (Joining Fetch) >> Joining
        }
        return buffer;
    }  

    Bytes& operator<<(Bytes& buffer, const std::optional<Fetch::Group_1>& grp)
    {
        if (grp.has_value()) {
            buffer << grp->joining; // (Joining Fetch) << Joining
        }
        return buffer;
    }

    /*
     * FetchCancel stream in
     */
    BytesSpan operator>>(BytesSpan buffer, FetchCancel& msg)
    {
        buffer = buffer >> msg.request_id; // (i)  >> RequestID
        return buffer;
    }

    /*
     * FetchCancel stream out
     */
    Bytes& operator<<(Bytes& buffer, const FetchCancel& msg)
    {
        Bytes payload;
        // fill out payload
        payload << msg.request_id; // (i)  << RequestID

        // fill out buffer
        ControlMessage message;
        message.type = static_cast<std::uint64_t>(ControlMessageType::kFetchCancel);
        message.payload = payload;
        buffer << message;
        return buffer;
    }


    /*
     * FetchOk stream in
     */
    BytesSpan operator>>(BytesSpan buffer, FetchOk& msg)
    {
        buffer = buffer >> msg.request_id; // (i)  >> RequestID
        buffer = buffer >> msg.end_of_track; // (8)  >> EndOfTrack
        buffer = buffer >> msg.end_location; // (Location)  >> EndLocation
        buffer = buffer >> msg.parameters; // (..)  >> Parameters
        buffer = buffer >> msg.track_extensions; // (tuple)  >> TrackExtensions
        return buffer;
    }

    /*
     * FetchOk stream out
     */
    Bytes& operator<<(Bytes& buffer, const FetchOk& msg)
    {
        Bytes payload;
        // fill out payload
        payload << msg.request_id; // (i)  << RequestID
        payload << msg.end_of_track; // (8)  << EndOfTrack
        payload << msg.end_location; // (Location)  << EndLocation
        payload << msg.parameters; // (..)  << Parameters
        payload << msg.track_extensions; // (tuple)  << TrackExtensions

        // fill out buffer
        ControlMessage message;
        message.type = static_cast<std::uint64_t>(ControlMessageType::kFetchOk);
        message.payload = payload;
        buffer << message;
        return buffer;
    }


    /*
     * RequestsBlocked stream in
     */
    BytesSpan operator>>(BytesSpan buffer, RequestsBlocked& msg)
    {
        buffer = buffer >> msg.maximum_request_id; // (i)  >> MaximumRequestID
        return buffer;
    }

    /*
     * RequestsBlocked stream out
     */
    Bytes& operator<<(Bytes& buffer, const RequestsBlocked& msg)
    {
        Bytes payload;
        // fill out payload
        payload << msg.maximum_request_id; // (i)  << MaximumRequestID

        // fill out buffer
        ControlMessage message;
        message.type = static_cast<std::uint64_t>(ControlMessageType::kRequestsBlocked);
        message.payload = payload;
        buffer << message;
        return buffer;
    }


    /*
     * Publish stream in
     */
    BytesSpan operator>>(BytesSpan buffer, Publish& msg)
    {
        buffer = buffer >> msg.request_id; // (i)  >> RequestID
        buffer = buffer >> msg.track_namespace; // (tuple)  >> TrackNamespace
        buffer = buffer >> msg.track_name; // (..)  >> TrackName
        buffer = buffer >> msg.track_alias; // (i)  >> TrackAlias
        buffer = buffer >> msg.parameters; // (..)  >> Parameters
        buffer = buffer >> msg.track_extensions; // (tuple)  >> TrackExtensions
        return buffer;
    }

    /*
     * Publish stream out
     */
    Bytes& operator<<(Bytes& buffer, const Publish& msg)
    {
        Bytes payload;
        // fill out payload
        payload << msg.request_id; // (i)  << RequestID
        payload << msg.track_namespace; // (tuple)  << TrackNamespace
        payload << msg.track_name; // (..)  << TrackName
        payload << msg.track_alias; // (i)  << TrackAlias
        payload << msg.parameters; // (..)  << Parameters
        payload << msg.track_extensions; // (tuple)  << TrackExtensions

        // fill out buffer
        ControlMessage message;
        message.type = static_cast<std::uint64_t>(ControlMessageType::kPublish);
        message.payload = payload;
        buffer << message;
        return buffer;
    }


    /*
     * PublishOk stream in
     */
    BytesSpan operator>>(BytesSpan buffer, PublishOk& msg)
    {
        buffer = buffer >> msg.request_id; // (i)  >> RequestID
        buffer = buffer >> msg.parameters; // (..)  >> Parameters
        return buffer;
    }

    /*
     * PublishOk stream out
     */
    Bytes& operator<<(Bytes& buffer, const PublishOk& msg)
    {
        Bytes payload;
        // fill out payload
        payload << msg.request_id; // (i)  << RequestID
        payload << msg.parameters; // (..)  << Parameters

        // fill out buffer
        ControlMessage message;
        message.type = static_cast<std::uint64_t>(ControlMessageType::kPublishOk);
        message.payload = payload;
        buffer << message;
        return buffer;
    }


    /*
     * ClientSetup stream in
     */
    BytesSpan operator>>(BytesSpan buffer, ClientSetup& msg)
    {
        buffer = buffer >> msg.setup_parameters; // (..)  >> SetupParameters
        return buffer;
    }

    /*
     * ClientSetup stream out
     */
    Bytes& operator<<(Bytes& buffer, const ClientSetup& msg)
    {
        Bytes payload;
        // fill out payload
        payload << msg.setup_parameters; // (..)  << SetupParameters

        // fill out buffer
        ControlMessage message;
        message.type = static_cast<std::uint64_t>(ControlMessageType::kClientSetup);
        message.payload = payload;
        buffer << message;
        return buffer;
    }


    /*
     * ServerSetup stream in
     */
    BytesSpan operator>>(BytesSpan buffer, ServerSetup& msg)
    {
        buffer = buffer >> msg.setup_parameters; // (..)  >> SetupParameters
        return buffer;
    }

    /*
     * ServerSetup stream out
     */
    Bytes& operator<<(Bytes& buffer, const ServerSetup& msg)
    {
        Bytes payload;
        // fill out payload
        payload << msg.setup_parameters; // (..)  << SetupParameters

        // fill out buffer
        ControlMessage message;
        message.type = static_cast<std::uint64_t>(ControlMessageType::kServerSetup);
        message.payload = payload;
        buffer << message;
        return buffer;
    }


   
    Bytes &operator<<(Bytes &buffer, ControlMessageType message_type)
    {
        UintVar varint = static_cast<std::uint64_t>(message_type);
        buffer << varint;
        return buffer;
    }

} // namespace

