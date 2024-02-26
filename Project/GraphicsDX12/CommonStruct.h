#ifndef _FRAMEWORK_GRAPHICSDX12_COMMONSTRUCT_H_
#define _FRAMEWORK_GRAPHICSDX12_COMMONSTRUCT_H_

namespace Framework::GraphicsDX12
{

    template<typename Type>
    concept IsCOMType = std::is_base_of_v<IUnknown, Type>;

    template<typename COMType> requires IsCOMType<COMType>
    class COMPTR
    {
    public:
        COMPTR() : m_ptr{ nullptr } {}
        COMPTR(COMType* ptr) : m_ptr{ ptr }
        {
            if (m_ptr != nullptr)
            {
                m_ptr->AddRef();
            }
        }

        COMPTR(const COMPTR& lvalue) : m_ptr{ lvalue.m_ptr }
        {
            if (m_ptr != nullptr)
            {
                m_ptr->AddRef();
            }
        }

        COMPTR(COMPTR&& rvalue) noexcept : m_ptr{ rvalue.m_ptr }
        {
            rvalue.m_ptr = nullptr;
        }

        ~COMPTR() noexcept
        {
            Core::SafeRelease(m_ptr);
        }

        COMPTR& operator=(const COMPTR& lvalue)
        {

            Core::SafeRelease(m_ptr);

            m_ptr = lvalue.m_ptr;
            if (m_ptr != nullptr)
            {
                m_ptr->AddRef();
            }

            return *this;

        }

        COMPTR& operator=(COMPTR&& rvalue) noexcept
        {

            m_ptr = rvalue.m_ptr;

            rvalue.m_ptr = nullptr;

            return *this;

        }

        COMType* operator->()
        {
            return m_ptr;
        }

        const COMType* operator->() const
        {
            return m_ptr;
        }

        operator COMType* ()
        {
            return m_ptr;
        }

        operator const COMType* ()
        {
            return m_ptr;
        }

        /// <summary>
        /// 기존 COM객체를 버립니다.
        /// </summary>
        void Reset()
        {
            Core::SafeRelease(m_ptr);
        }


        /// <summary>
        /// 새로운 COM객체를 생성할 때 아웃 파라미터가 필요한 경우 사용합니다. 기존에 가지고있던 객체는 버립니다.
        /// </summary>
        /// <returns></returns>
        COMType** ResetByOutParameter()
        {
            Core::SafeRelease(m_ptr);
            return &m_ptr;
        }

    private:

        COMType* m_ptr;

    };

}

#endif